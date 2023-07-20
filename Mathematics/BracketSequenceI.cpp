#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;

ll modExpo(ll a, ll b){
	if(b == 1)return a;
	ll res = modExpo(a, b/2);
	res = res * res % MOD;
	res = res * (b%2 ? a : 1);
	return res % MOD;
}

ll fact(ll num){
	ll res = 1;
	for(int i = 2; i <= num; i++) 
		res = res * i % MOD;
	return res;
}

int main(){

	ll n;
	cin >> n;

	if(n%2){
		cout << 0;
		return 0;
	}

	n /= 2;

	ll factN = fact(n), fact2N = fact(2 * n % MOD);
	ll res = fact2N * modExpo(factN, MOD-2) % MOD * modExpo(factN, MOD-2) % MOD * modExpo(n+1, MOD-2) % MOD;

	cout << res;
	return 0;
}