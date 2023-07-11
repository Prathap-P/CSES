#include<iostream>
using namespace std;

#define ll long long

ll xPowerY(ll a, ll b, ll MOD){
	if(b == 0)return 1;
	if(a == 0)return 0;
	if(b == 1)return a;

	ll ans = xPowerY(a, b/2, MOD);
	ans = (ans * ans)%MOD;
	ans *= ((b%2 == 1) ? a : 1);

	return ans%MOD;
}

int main(){

	int count;
	cin >> count;

	while(count--){
		ll a, b, c;
		cin >> a >> b >> c;
		ll bPowerC = xPowerY(b, c, 1000000006);
	
		cout << xPowerY(a, bPowerC, 1000000007) << '\n';
	}

	return 0;
}