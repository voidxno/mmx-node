
const max_retry = 2;
const latency_gain = 0.1;
const check_interval_ms = 10 * 1000;
const error_timeout_ms = 2 * check_interval_ms;

const express = require('express');
const axios = require("axios");
const https = require('https');
const http = require('http');
const fs = require('fs');

var remotes = JSON.parse(fs.readFileSync('remotes.json', 'utf8'));

var targets = ['http://localhost:11380/wapi'].concat(remotes);

console.log("Targets:");
console.log(targets);

var servers = [];
for(const entry of targets) {
	servers.push({url: entry, count: 0, errors: 0, latency: 1000, timeout: 0, last_response: 0});
}
servers[0].latency = 0;

var http_proxy = require('http-proxy');
var proxy = http_proxy.createProxyServer({});

proxy.on('proxyRes', function(proxyRes) {
	proxyRes.headers['Access-Control-Allow-Origin'] = "*";
});

var app = express();

app.all('*', function(req, res)
{
	const hop_count = req.get('x-hop-count');
	const is_health_check = req.get('x-health-check');
	
	console.log(req.method + ' ' + req.url + ' (hop ' + (hop_count ? hop_count : 0) + ')' + (is_health_check ? " (check)" : ""));
	
	if(req.url == "/server/status") {
		res.send(JSON.stringify(servers, null, 4) + '\n');
		return;
	}
	const time_begin = Date.now();
	
	var server = servers[0];
	if(!is_health_check) {
		if(!hop_count || hop_count <= max_retry) {
			var is_fallback = server.timeout > time_begin;
			for(const entry of servers) {
				if(time_begin > entry.timeout) {
					if(entry.latency < server.latency || is_fallback) {
						is_fallback = false;
						server = entry;
					}
				}
			}
		}
		server.count++;
	}
	
	res.on('finish', function() {
		if(res.statusCode >= 500) {
			server.errors++;
			server.timeout = Date.now() + error_timeout_ms;
		}
		
		const now = Date.now();
		const latency = now - time_begin;
		server.latency = parseInt(server.latency * (1 - latency_gain) + latency * latency_gain);
		server.last_response = now;
		
		console.log(req.method + ' ' + server.url + req.url + ' => status ' + res.statusCode + ', took ' + latency + ' ms, latency ' + server.latency + ' ms');
    });
    
	proxy.web(req, res, {
		target: server.url,
		headers: {'x-hop-count': (hop_count ? hop_count + 1 : 1)}
	}, function(err) {
		try {
			res.status(500);
		} finally {
			res.send(err.code);
		}
		console.log(err);
	});
});

function health_check() {
	for(const server of servers) {
		const time_begin = Date.now();
		axios.get(server.url + '/node/info', {headers: {'x-health-check': true}})
			.then((res) => {
				var info = {};
				if(res.status == 200) {
					if(res.data) {
						info = res.data;
					}
					server.timeout = 0;
				}
				const now = Date.now();
				const latency = now - time_begin;
				if(now - server.last_response > check_interval_ms) {
					server.latency = latency + 100;
				} else {
					server.latency = Math.max(server.latency, latency);
				}
				console.log('CHECK ' + server.url + ' => status ' + res.status + ', height ' + info.height + ', latency ' + latency + ' ms');
			}).catch((err) => {
				server.timeout = Date.now() + error_timeout_ms;
				console.log('CHECK ' + server.url + ' failed with: ' + err.code);
			});
	}
}

health_check();

setInterval(health_check, check_interval_ms);

{
	http.createServer(app).listen(80);
	
	console.log("Listening on port 80 ...");
}

const cert_path = '/etc/letsencrypt/live/rpc.mmx.network/';

if(fs.existsSync(cert_path))
{
	var options = {
		key: fs.readFileSync(cert_path + 'privkey.pem'),
		cert: fs.readFileSync(cert_path + 'fullchain.pem'),
		ca: fs.readFileSync(cert_path + 'chain.pem')
	};

	https.createServer(options, app).listen(443);
	
	console.log("Listening on port 443 ...");
}

