
const WITHDRAW_FACTOR = 90;

var owner;

function init(owner_)
{
	owner = bech32(owner_);
}

function deposit() public {}

function withdraw(amount, currency) public
{
	if(this.user != owner) {
		fail("user != owner", 1);
	}
	amount = uint(amount);
	currency = bech32(currency);
	
	var ret_amount = amount;
	
	if(currency == bech32()) {
		ret_amount = (amount * WITHDRAW_FACTOR) / 100;
	}
	send(owner, ret_amount, currency, "mmx_virtual_plot_withdraw");
	send(bech32(), amount - ret_amount, currency, "mmx_virtual_plot_burn");
}
