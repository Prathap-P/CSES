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

	int n, k;
	cin >> n >> k;	

	ll a = (n - 1 + k) % MOD;
	a = fact(a);

	ll b = fact(n-1), c = fact(k);

	ll res = a * modExpo(b, MOD-2) % MOD * modExpo(c, MOD-2) % MOD;

	cout << res;
	return 0;
}