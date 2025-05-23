
Vue.component('explore-menu', {
	data() {
		return {
			input: null,
			error: null
		}
	},
	methods: {
		submit() {
			const hex = /[0-9A-Fa-f]{8}/g;
			if(this.input) {
				this.error = null;
				if(this.input.startsWith("mmx1")) {
					this.$router.push("/explore/address/" + this.input);
				}
				else if(hex.test(this.input)) {
					if(this.input.length == 64) {
						fetch(WAPI_URL + '/header?hash=' + this.input)
							.then(response => {
								if(response.ok) {
									this.$router.push("/explore/block/hash/" + this.input);
								} else {
									this.$router.push("/explore/transaction/" + this.input);
								}
						});
					} else if(this.input.length == 66) {
						this.$router.push("/explore/farmer/" + this.input);
					} else {
						this.error = true;
					}
				}
				else if(parseInt(this.input) != NaN) {
					this.$router.push("/explore/block/height/" + this.input);
				}
				else {
					this.error = true;
				}
			}
		}
	},
	template: `
		<div>
			<v-text-field class="mx-2"
				v-model="input"
				@keyup.enter="submit"
				@click:append="submit"
				:error="error"
				:placeholder="$t('explore_menu.placeholder')"
				append-icon="mdi-magnify"></v-text-field>

			<v-tabs class="mb-2">
				<v-tab to="/explore/blocks">{{ $t('explore_menu.blocks') }}</v-tab>
				<v-tab to="/explore/transactions">{{ $t('explore_menu.transactions') }}</v-tab>
				<v-tab to="/explore/farmers">{{ $t('explore_menu.farmers') }}</v-tab>
			</v-tabs>
		</div>
	`
})

Vue.component('blocks-table', {
	props: {
		data: [],
		loaded: {
			type: Boolean,
			default: true
		}
	},
	computed: {
		headers() {
			return [
				{ text: this.$t('explore_blocks.height'), value: 'height', width: "5%"},
				{ text: "VDF", value: 'vdf_count' },
				{ text: this.$t('explore_blocks.tx'), value: 'tx_count' },
				{ text: this.$t('explore_blocks.k'), value: 'ksize' },
				{ text: this.$t('explore_blocks.score'), value: 'score' },
				{ text: this.$t('explore_blocks.reward'), value: 'reward' },
				{ text: "TX Fees", value: 'tx_fees' },
				{ text: this.$t('explore_blocks.size'), value: 'static_cost_ratio' },
				{ text: this.$t('explore_blocks.cost'), value: 'total_cost_ratio' },
				{ text: this.$t('explore_blocks.hash'), value: 'hash' },
			]
		}
	},
	template: `
		<v-data-table
			:headers="headers"
			:items="data"
			:loading="!loaded"
			hide-default-footer
			disable-sort
			disable-pagination
			class="elevation-2"
		>
			<template v-slot:progress>
				<v-progress-linear indeterminate absolute top></v-progress-linear>
				<v-skeleton-loader type="table-row-divider@6" />
			</template>

			<template v-slot:item.height="{ item }">
				<router-link :to="'/explore/block/height/' + item.height">{{item.height}}</router-link>
			</template>
			
			<template v-slot:item.vdf_count="{ item }">
				+{{item.vdf_count}}
			</template>
			
			<template v-slot:item.ksize="{ item }">
				k{{item.ksize}}
			</template>

			<template v-slot:item.reward="{ item }">
				{{item.reward_addr ? (item.reward_amount.value).toFixed(3) + " MMX" : null}}
			</template>
			
			<template v-slot:item.tx_fees="{ item }">
				{{item.tx_count ? (item.tx_fees.value).toFixed(3) + " MMX" : null}}
			</template>
			
			<template v-slot:item.static_cost_ratio="{ item }">
				{{(item.static_cost_ratio * 100).toFixed(1)}}&nbsp;%
			</template>
			
			<template v-slot:item.total_cost_ratio="{ item }">
				{{(item.total_cost_ratio * 100).toFixed(1)}}&nbsp;%
			</template>

			<template v-slot:item.hash="{ item }">
				<router-link :to="'/explore/block/hash/' + item.hash">{{get_short_hash(item.hash, 16)}}</router-link>
			</template>

		</v-data-table>
		`
})

Vue.component('explore-blocks', {
	props: {
		limit: Number
	},
	data() {
		return {
			data: [],
			timer: null,
			loaded: false
		}
	},
	methods: {
		update() {
			fetch(WAPI_URL + '/headers?limit=' + this.limit)
				.then(response => response.json())
				.then(data => {
					this.data = data;
					this.loaded = true;
				});
		}
	},
	created() {
		this.update();
		this.timer = setInterval(() => { this.update(); }, 10000);
	},
	beforeDestroy() {
		clearInterval(this.timer);
	},
	template: `
		<blocks-table :data="data" :loaded="loaded"></blocks-table>
		`
})

Vue.component('explore-transactions', {
	props: {
		limit: Number
	},
	data() {
		return {
			data: [],
			timer: null,
			loaded: false
		}
	},
	computed: {
		headers() {
			return [
				{ text: this.$t('explore_transactions.height'), value: 'height' },
				{ text: this.$t('explore_transactions.type'), value: 'type' },
				{ text: this.$t('explore_transactions.fee'), value: 'fee' },
				{ text: this.$t('explore_transactions.n_in'), value: 'inputs.length' },
				{ text: this.$t('explore_transactions.n_out'), value: 'outputs.length' },
				{ text: this.$t('explore_transactions.n_op'), value: 'operations.length' },
				{ text: this.$t('explore_transactions.transaction_id'), value: 'transaction_id' },
				{ text: this.$t('account_tx_history.time'), value: 'time' },
			]
		}
	},
	methods: {
		update() {
			fetch(WAPI_URL + '/transactions?limit=' + this.limit)
				.then(response => response.json())
				.then(data => {
					this.data = data;
					this.loaded = true;
				});
		}
	},
	created() {
		this.update();
		this.timer = setInterval(() => { this.update(); }, 10000);
	},
	beforeDestroy() {
		clearInterval(this.timer);
	},
	template: `
		<v-data-table
			:headers="headers"
			:items="data"
			:loading="!loaded"
			hide-default-footer
			disable-sort			
			disable-pagination
			class="elevation-2"
		>
			<template v-slot:progress>
				<v-progress-linear indeterminate absolute top></v-progress-linear>
				<v-skeleton-loader type="table-row-divider@6" />
			</template>

			<template v-slot:item.height="{ item }">
				<router-link :to="'/explore/block/height/' + item.height">{{item.height}}</router-link>
			</template>

			<template v-slot:item.type="{ item }">
				{{item.note ? item.note : ""}}
			</template>

			<template v-slot:item.fee="{ item }">
				<b :class="{'red--text': item.did_fail}">{{item.fee.value}}</b>
			</template>

			<template v-slot:item.transaction_id="{ item }">
				<router-link :to="'/explore/transaction/' + item.id">{{get_short_hash(item.id, 16)}}</router-link>
			</template>

			<template v-slot:item.time="{ item }">
				{{new Date(item.time_stamp).toLocaleString()}}
			</template>

		</v-data-table>
		`
})

Vue.component('explore-farmers', {
	props: {
		limit: Number
	},
	data() {
		return {
			data: [],
			timer: null,
			loaded: false
		}
	},
	computed: {
		headers() {
			return [
				{ text: this.$t('explore_farmers.no_blocks'), value: 'block_count'},
				{ text: this.$t('explore_farmers.farmer_key'), value: 'farmer_key'},
			]
		}
	},
	methods: {
		update() {
			fetch(WAPI_URL + '/farmers?limit=' + this.limit)
				.then(response => response.json())
				.then(data => {
					this.data = data;
					this.loaded = true;
				});
		}
	},
	created() {
		this.update();
		this.timer = setInterval(() => { this.update(); }, 30000);
	},
	beforeDestroy() {
		clearInterval(this.timer);
	},
	template: `
		<v-data-table
			:headers="headers"
			:items="data"
			:loading="!loaded"
			hide-default-footer
			disable-sort
			disable-pagination
			class="elevation-2"
		>
			<template v-slot:progress>
				<v-progress-linear indeterminate absolute top></v-progress-linear>
				<v-skeleton-loader type="table-row-divider@6" />
			</template>
			<template v-slot:item.farmer_key="{ item }">
				<router-link :to="'/explore/farmer/' + item.farmer_key">{{item.farmer_key}}</router-link>
			</template>
		</v-data-table>
		`
})

Vue.component('block-view', {
	props: {
		hash: String,
		height: Number
	},
	data() {
		return {
			data: null,
			loading: false
		}
	},
	methods: {
		update() {
			let url = null;
			if(this.hash) {
				url = WAPI_URL + '/block?hash=' + this.hash;
			}
			if(this.height >= 0) {
				url = WAPI_URL + '/block?height=' + this.height;
			}
			if(url) {
				this.loading = true;
				fetch(url)
					.then(response => {
						if(response.ok) {
							response.json()
								.then(data => {
									this.loading = false;
									this.data = data;
								});
						} else {
							this.loading = false;
							this.data = null;
						}
					});
			}
		}
	},
	watch: {
		hash() {
			this.update();
		},
		height() {
			this.update();
		}
	},
	created() {
		this.update();
	},
	template: `
		<div>
			<v-toolbar dense flat class="pa-0 no-padding">
				<template v-if="data">
					<v-btn outlined :to="'/explore/block/hash/' + data.prev"><v-icon>mdi-arrow-left</v-icon>{{ $t('block_view.previous') }}</v-btn>
					<v-spacer></v-spacer>
					<v-btn outlined :to="'/explore/block/height/' + (data.height + 1)">{{ $t('block_view.next') }}<v-icon>mdi-arrow-right</v-icon></v-btn>
				</template>

				<template v-if="!data && height">
					<div v-if="height > 0">
						<v-btn outlined :to="'/explore/block/height/' + (height - 1)"><v-icon>mdi-arrow-left</v-icon>{{ $t('block_view.previous') }}</v-btn>
					</div>
					<v-spacer></v-spacer>
					<v-btn outlined :to="'/explore/block/height/' + (height + 1)">{{ $t('block_view.next') }}<v-icon>mdi-arrow-right</v-icon></v-btn>
				</template>
				<v-progress-linear :active="loading" indeterminate absolute top></v-progress-linear>
			</v-toolbar>

			<v-card class="my-2">
			<v-card-text>
				<template v-if="data">
					<v-chip label>{{ $t('block_view.block') }}</v-chip>
					<v-chip label>{{ data.height }}</v-chip>
					<v-chip label>{{ data.hash }}</v-chip>
				</template>
							
				<v-alert
					border="left"
					colored-border
					type="error"
					v-if="!data && !loading"
					elevation="2"
					class="my-2"
				>
					{{ $t('block_view.no_such_block') }}
				</v-alert>
	
				<template v-if="data">
					<v-card class="my-2">
						<v-simple-table>
							<template v-slot:default>
								<tbody>
									<tr>
										<td class="key-cell">{{ $t('block_view.height') }}</td>
										<td>{{data.height}}</td>
									</tr>
									<tr>
										<td class="key-cell">{{ $t('block_view.hash') }}</td>
										<td>{{data.hash}}</td>
									</tr>
									<tr>
										<td class="key-cell">{{ $t('block_view.previous') }}</td>
										<td>{{data.prev}}</td>
									</tr>
									<tr>
										<td class="key-cell">{{ $t('block_view.time') }}</td>
										<td>{{new Date(data.time_stamp).toLocaleString()}}</td>
									</tr>
									<template v-if="data.reward_addr">
										<tr>
											<td class="key-cell">Reward Address</td>
											<td><router-link :to="'/explore/address/' + data.reward_addr">{{data.reward_addr}}</router-link></td>
										</tr>
									</template>
									<template v-if="data.reward_contract">
										<tr>
											<td class="key-cell">Reward Contract</td>
											<td><router-link :to="'/explore/address/' + data.reward_contract">{{data.reward_contract}}</router-link></td>
										</tr>
									</template>
									<template v-if="data.reward_account">
										<tr>
											<td class="key-cell">Farmer Address</td>
											<td><router-link :to="'/explore/address/' + data.reward_account">{{data.reward_account}}</router-link></td>
										</tr>
									</template>
									<tr>
										<td class="key-cell">Block Reward</td>
										<td><b>{{data.reward_amount.value}}</b>&nbsp; MMX</td>
									</tr>
									<tr>
										<td class="key-cell">TX Fees</td>
										<td><b>{{data.tx_fees.value}}</b>&nbsp; MMX</td>
									</tr>
									<tr>
										<td class="key-cell">{{ $t('block_view.tx_count') }}</td>
										<td>{{data.tx_count}}</td>
									</tr>
									<tr>
										<td class="key-cell">{{ $t('block_view.time_diff') }}</td>
										<td>{{data.time_diff}}</td>
									</tr>
									<tr>
										<td class="key-cell">{{ $t('block_view.space_diff') }}</td>
										<td>{{data.space_diff}}<template v-if="data.is_space_fork"> (updated)</template></td>
									</tr>
									<tr>
										<td class="key-cell">Reward Vote</td>
										<td>{{data.reward_vote}}</td>
									</tr>
									<tr>
										<td class="key-cell">Reward Vote Sum</td>
										<td>{{data.reward_vote_sum}} / {{data.reward_vote_count}} ({{(data.reward_vote_count / ((data.height % 8640) + 1) * 100).toFixed(1)}} %)</td>
									</tr>
									<tr>
										<td class="key-cell">Base Reward</td>
										<td><b>{{data.base_reward.value}}</b>&nbsp; MMX</td>
									</tr>
									<tr>
										<td class="key-cell">Avg. TX Fee</td>
										<td><b>{{data.average_txfee.value}}</b>&nbsp; MMX</td>
									</tr>
									<tr>
										<td class="key-cell">VDF Height</td>
										<td>{{data.vdf_height}}</td>
									</tr>
									<tr>
										<td class="key-cell">VDF Count</td>
										<td>{{data.vdf_count}}</td>
									</tr>
									<tr>
										<td class="key-cell">{{ $t('block_view.vdf_iterations') }}</td>
										<td>{{data.vdf_iters}}</td>
									</tr>
									<template v-for="(addr, index) in data.vdf_reward_addr">
										<tr>
											<td class="key-cell">Timelord [{{index}}]</td>
											<td><router-link :to="'/explore/address/' + addr">{{addr}}</router-link></td>
										</tr>
									</template>
									<template v-if="data.vdf_reward_payout">
										<tr>
											<td class="key-cell">Timelord Reward</td>
											<td><router-link :to="'/explore/address/' + data.vdf_reward_payout">{{data.vdf_reward_payout}}</router-link></td>
										</tr>
									</template>
									<tr>
										<td class="key-cell">{{ $t('block_view.k_size') }}</td>
										<td>{{data.ksize}}</td>
									</tr>
									<tr>
										<td class="key-cell">{{ $t('block_view.proof_score') }}</td>
										<td>{{data.score}}</td>
									</tr>
									<tr>
										<td class="key-cell">No. Proofs</td>
										<td>{{data.proof.length}}</td>
									</tr>
									<tr>
										<td class="key-cell">Space Fork</td>
										<td>{{data.space_fork_proofs}} / {{data.space_fork_len}}</td>
									</tr>
									<template v-if="data.proof[0]">
										<tr>
											<td class="key-cell">{{ $t('block_view.plot_id') }}</td>
											<td>{{data.proof[0].plot_id}}</td>
										</tr>
										<tr>
											<td class="key-cell">Challenge</td>
											<td>{{data.proof[0].challenge}}</td>
										</tr>
									</template>
									<tr>
										<td class="key-cell">{{ $t('block_view.farmer_key') }}</td>
										<td><router-link :to="'/explore/farmer/' + data.farmer_key">{{data.farmer_key}}</router-link></td>
									</tr>
								</tbody>
							</template>
						</v-simple-table>
					</v-card>
	
					<v-card class="my-2">
						<v-simple-table v-if="data.tx_list.length">
							<thead>
								<tr>
									<th class="key-cell"></th>
									<th>{{ $t('block_view.inputs') }}</th>
									<th>{{ $t('block_view.outputs') }}</th>
									<th>{{ $t('block_view.operations') }}</th>
									<th>{{ $t('block_view.transaction_id') }}</th>
								</tr>
							</thead>
							<tbody>
								<tr v-for="(item, index) in data.tx_list" :key="index">
									<td class="key-cell">TX[{{index}}]</td>
									<td>{{item.inputs.length + (item.exec_result ? item.exec_result.inputs.length : 0)}}</td>
									<td>{{item.outputs.length + (item.exec_result ? item.exec_result.outputs.length : 0)}}</td>
									<td>{{item.execute.length}}</td>
									<td><router-link :to="'/explore/transaction/' + item.id">{{item.id}}</router-link></td>
								</tr>
							</tbody>
						</v-simple-table>
					</v-card>
				</template>
			</v-card-text>
			</v-card>
		</div>
	`
})

Vue.component('transaction-view', {
	props: {
		id: String
	},
	data() {
		return {
			data: null,
			timer: null,
			loading: false
		}
	},
	methods: {
		update() {
			if(this.id) {
				this.loading = true;
				fetch(WAPI_URL + '/transaction?id=' + this.id)
					.then(response => {
						if(response.ok) {
							response.json()
								.then(data => {
									for(const op of data.operations) {
										delete op.solution;
									}
									this.loading = false;
									this.data = data;
								});
						} else {
							this.loading = false;
							this.data = null;
						}
					});
			}
		}
	},
	watch: {
		id() {
			this.update();
		}
	},
	created() {
		this.update();
		this.timer = setInterval(() => { this.update(); }, 10000);
	},
	beforeDestroy() {
		clearInterval(this.timer);
	},
	template: `
		<v-card class="my-2">
		<v-progress-linear :active="loading" indeterminate absolute top></v-progress-linear>
		<v-card-text>
			<v-chip label>{{ $t('transaction_view.transaction') }}</v-chip>
			<v-chip label>{{ id }}</v-chip>
							
			<v-alert
				border="left"
				colored-border
				type="error"
				v-if="!data && !loading"
				elevation="2"
				class="my-2"
			>
				{{ $t('transaction_view.no_such_transaction') }}
			</v-alert>
	
			<template v-if="data">
				<v-card class="my-2">
					<v-simple-table>
						<tbody>
						<tr>
							<td class="key-cell">{{ $t('transaction_view.height') }}</td>
							<td>
								<template v-if="data.height != null">
									<router-link :to="'/explore/block/height/' + data.height">{{data.height}}</router-link>
								</template>
								<template v-if="data.height == null"><i>{{ $t('common.pending') }}</i></template>
							</td>
						</tr>
						<tr v-if="data.did_fail" class="red--text">
							<td class="key-cell">{{ $t('transaction_view.message') }}</td>
							<td>{{data.message}}</td>
						</tr>
						<tr v-if="data.confirm">
							<td class="key-cell">{{ $t('transaction_view.confirmed') }}</td>
							<td>{{data.confirm}}</td>
						</tr>
						<tr v-if="data.expires < 4294967295">
							<td class="key-cell">{{ $t('transaction_view.expires') }}</td>
							<td>{{data.expires}}</td>
						</tr>
						<tr>
							<td class="key-cell">{{ $t('transaction_view.note') }}</td>
							<td>{{data.note}}</td>
						</tr>
						<tr v-if="data.time">
							<td class="key-cell">{{ $t('transaction_view.time') }}</td>
							<td>{{new Date(data.time_stamp).toLocaleString()}}</td>
						</tr>
						<tr v-if="data.deployed">
							<td class="key-cell">{{ $t('transaction_view.address') }}</td>
							<td><router-link :to="'/explore/address/' + data.address">{{data.address}}</router-link></td>
						</tr>
						<tr v-if="data.sender">
							<td class="key-cell">{{ $t('transaction_view.sender') }}</td>
							<td><router-link :to="'/explore/address/' + data.sender">{{data.sender}}</router-link></td>
						</tr>
						<tr>
							<td class="key-cell">{{ $t('transaction_view.cost') }}</td>
							<td><b>{{data.cost.value}}</b>&nbsp; MMX</td>
						</tr>
						<tr>
							<td class="key-cell">{{ $t('transaction_view.fee') }}</td>
							<td><b>{{data.fee.value}}</b>&nbsp; MMX</td>
						</tr>
						</tbody>
					</v-simple-table>
				</v-card>
	
				<v-card class="my-2">
					<v-simple-table v-if="data.inputs.length">
						<thead>
						<tr>
							<th class="key-cell"></th>
							<th>{{ $t('transaction_view.amount') }}</th>
							<th>{{ $t('transaction_view.token') }}</th>
							<th>{{ $t('transaction_view.address') }}</th>
							<th>Memo</th>
						</tr>
						</thead>
						<tbody>
						<tr v-for="(item, index) in data.inputs" :key="index">
							<td class="key-cell">{{ $t('transaction_view.input') }}[{{index}}]</td>
							<td><b>{{item.value}}</b></td>
							<template v-if="item.is_native">
								<td>{{item.symbol}}</td>
							</template>
							<template v-if="!item.is_native">
								<td><router-link :to="'/explore/address/' + item.contract">{{item.is_nft ? "[NFT]" : item.symbol}}</router-link></td>
							</template>
							<td><router-link :to="'/explore/address/' + item.address">{{item.address}}</router-link></td>
							<td>{{item.memo}}</td>
						</tr>
						</tbody>
					</v-simple-table>
				</v-card>
	
				<v-card class="my-2">
					<v-simple-table v-if="data.outputs.length">
						<thead>
						<tr>
							<th class="key-cell"></th>
							<th>{{ $t('transaction_view.amount') }}</th>
							<th>{{ $t('transaction_view.token') }}</th>
							<th>{{ $t('transaction_view.address') }}</th>
							<th>Memo</th>
						</tr>
						</thead>
						<tbody>
						<tr v-for="(item, index) in data.outputs" :key="index">
							<td class="key-cell">{{ $t('transaction_view.output') }}[{{index}}]</td>
							<td><b>{{item.value}}</b></td>
							<template v-if="item.is_native">
								<td>{{item.symbol}}</td>
							</template>
							<template v-if="!item.is_native">
								<td><router-link :to="'/explore/address/' + item.contract">{{item.is_nft ? "[NFT]" : item.symbol}}</router-link></td>
							</template>
							<td><router-link :to="'/explore/address/' + item.address">{{item.address}}</router-link></td>
							<td>{{item.memo}}</td>
						</tr>
						</tbody>
					</v-simple-table>
				</v-card>
	
				<div class="my-2" v-for="(op, index) in data.operations" :key="index">				
					<v-chip label>Operation[{{index}}]</v-chip>
					<v-chip label>{{op.__type}}</v-chip>
					<object-table :data="op" class="my-2"></object-table>
				</div>
	
				<div class="my-2" v-if="data.deployed">
					<v-chip label>{{data.deployed.__type}}</v-chip>
					<object-table :data="data.deployed" class="my-2"></object-table>
				</div>
	
			</template>
		</v-card-text>
		</v-card>
	`
})

Vue.component('farmer-view', {
	props: {
		farmer_key: String,
		limit: Number
	},
	data() {
		return {
			data: null,
			blocks: [],
			timer: null,
			loaded: false
		}
	},
	methods: {
		update() {
			fetch(WAPI_URL + '/farmer?id=' + this.farmer_key)
				.then(response => response.json())
				.then(data => {
					this.data = data;
				});
			fetch(WAPI_URL + '/farmer/blocks?id=' + this.farmer_key + '&limit=' + this.limit)
				.then(response => response.json())
				.then(data => {
					this.blocks = data;
					this.loaded = true;
				});
		}
	},
	created() {
		this.update();
		this.timer = setInterval(() => { this.update(); }, 30000);
	},
	beforeDestroy() {
		clearInterval(this.timer);
	},
	template: `
		<v-card class="my-2">
		<v-card-text>
			<v-chip label>Farmer</v-chip>
			<v-chip label>{{farmer_key}}</v-chip>
			<template v-if="data">
				<v-card class="my-2">
					<v-simple-table>
						<tbody>
						<tr>
							<td class="key-cell">No. Blocks</td>
							<td>{{data.block_count}}</td>
						</tr>
						<tr>
							<td class="key-cell">Total Rewards</td>
							<td><b>{{data.total_reward_value}}</b>&nbsp; MMX</td>
						</tr>
						</tbody>
					</v-simple-table>
				</v-card>
				<v-card class="my-2">
					<v-simple-table>
						<thead>
						<tr>
							<th>Reward</th>
							<th></th>
							<th>{{ $t('transaction_view.address') }}</th>
						</tr>
						</thead>
						<tbody>
						<tr v-for="item in data.rewards" :key="item.address">
							<td><b>{{item.value}}</b></td>
							<td>MMX</td>
							<td><router-link :to="'/explore/address/' + item.address">{{item.address}}</router-link></td>
						</tr>
						</tbody>
					</v-simple-table>
				</v-card>
			</template>
			<blocks-table :data="blocks" :loaded="loaded"></blocks-table>
		</v-card-text>
		</v-card>
	`
})

Vue.component('address-view', {
	props: {
		address: String
	},
	data() {
		return {
			data: null
		}
	},
	methods: {
		update() {
			this.loading = true;
			fetch(WAPI_URL + '/contract?id=' + this.address)
				.then(response => {
					if(response.ok) {
						response.json()
							.then(data => {
								this.loading = false;
								this.data = data;
							});
					} else {
						this.loading = false;
						this.data = null;
					}
				});
		}
	},
	watch: {
		address() {
			this.update();
		}
	},
	created() {
		this.update();
	},
	template: `
		<v-card class="my-2">
		<v-card-text>
			<v-chip label>{{ $t('common.address') }}</v-chip>
			<v-chip label>{{ address }}</v-chip>

			<balance-table :address="address" :show_empty="true" class="my-2"></balance-table>

			<div v-if="data">
				<v-chip label class="my-2">{{ data.__type }}</v-chip>
				<object-table :data="data"></object-table>
			</div>

			<address-history-table :address="address" :limit="200" :show_empty="false" class="my-2"></address-history-table>
		</v-card-text>
		</v-card>
	`
})

Vue.component('address-history-table', {
	props: {
		address: String,
		limit: Number,
		show_empty: Boolean
	},
	data() {
		return {
			data: [],
			loaded: false,
			timer: null		
		}
	},	
	computed: {
		headers() {
			return [
				{ text: this.$t('address_history_table.height'), value: 'height'},
				{ text: this.$t('address_history_table.type'), value: 'type'},
				{ text: this.$t('address_history_table.amount'), value: 'amount'},
				{ text: this.$t('address_history_table.token'), value: 'token'},
				{ text: "Transaction ID", value: 'txid'},
				{ text: "Memo", value: 'memo'},
				{ text: this.$t('address_history_table.time'), value: 'time'},
			]
		}
	},
	methods: {
		update() {
			fetch(WAPI_URL + '/address/history?limit=' + this.limit + '&id=' + this.address)
				.then(response => response.json())
				.then(data => {
					this.loaded = true;
					this.data = data;
				}).catch(() => {
					this.loaded = true;
				});
		}
	},
	watch: {
		address() {
			this.update();
		},
		limit() {
			this.update();
		}
	},
	created() {
		this.update();
		this.timer = setInterval(() => { this.update(); }, 60000);
	},
	beforeDestroy() {
		clearInterval(this.timer);
	},
	template: `
		<v-data-table
			:headers="headers"
			:items="data"
			:loading="!loaded"
			hide-default-footer
			disable-sort
			disable-pagination
			class="elevation-2"
			v-if="!loaded || loaded && (data.length || show_empty)"
		>
			<template v-slot:item.height="{ item }">
				<router-link :to="'/explore/block/height/' + item.height">{{item.height}}</router-link>
			</template>
			
			<template v-slot:item.type="{ item }">
				<span :class="get_tx_type_color(item.type, $vuetify.theme.dark)">{{item.type}}</span>
			</template>

			<template v-slot:item.amount="{ item }">
				<b>{{ item.value }}</b>
			</template>

			<template v-slot:item.token="{ item }">
				<template v-if="item.is_native">
					{{item.symbol}}
				</template>
				<template v-else>
					<router-link :to="'/explore/address/' + item.contract">{{item.is_nft ? "[NFT]" : item.symbol}}</router-link>
				</template>
			</template>

			<template v-slot:item.memo="{ item }">
				<span style="word-break: break-all;">{{ item.memo }}</span>
			</template>

			<template v-slot:item.txid="{ item }">
				<router-link :to="'/explore/transaction/' + item.txid">{{get_short_hash(item.txid)}}</router-link>
			</template>

			<template v-slot:item.time="{ item }">
				<span class="text-no-wrap">{{ new Date(item.time_stamp).toLocaleString() }}</span>
			</template>

		</v-data-table>
		`
})

Vue.component('object-table', {
	props: {
		data: Object
	},
	data() {
		return {
			tt: [],
		}
	},
	methods: {
		stringify(value) {
			return JSON.stringify(value, null, 4);
		}
	},
	template: `
		<v-card>
			<v-simple-table class="object-table">
				<tbody>
					<template v-for="(value, key) in data" :key="key">
						<tr v-if="key != '__type'">
							<td class="key-cell">{{ key }}</td>
							<td v-if="value instanceof Object && value.length > 0">

									<v-btn-toggle v-model="tt[key]" class="float-right mr-n4">
										<v-btn fab x-small> 
											<v-icon v-if="tt[key] != 0">mdi-arrow-expand</v-icon>
											<v-icon v-else>mdi-arrow-collapse</v-icon>
										</v-btn>
									</v-btn-toggle>				
		

								<div v-if="tt[key] != 0" style="overflow-wrap: anywhere;">
									{{ value }}
								</div>

								<div v-else>
									<div style="white-space: pre-wrap; overflow-wrap: anywhere;">{{ stringify(value) }}</div>
								</div>

							</td>
							<td v-else>
								{{ value }}
							</td>
						</tr>
					</template>
				</tbody>
			</v-simple-table>
		</v-card>
		`
})
