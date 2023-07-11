#include<iostream>
#include<cmath>
using namespace std;

#define ll long long
#define MOD 1000000007

ll aPowerB(ll a, ll b){
	if(b == 0)return 1;
	if(a == 0)return 0;
	if(b == 1)return a;

	ll ans = aPowerB(a, b/2);
	ans = (ans * ans)%MOD;
	ans *= ((b%2 == 1) ? a : 1);

	return ans%MOD;
}

int main(){

	int count;
	cin >> count;

	while(count--){
		ll a, b;
		cin >> a >> b;
	
		cout << aPowerB(a, b) << '\n';
	}

	return 0;
}