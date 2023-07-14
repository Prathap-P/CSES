#include<iostream>
#include<cmath>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll seriesSum(ll n){
	ll res = n % MOD;
	res = (res * ((n-1) % MOD)) % MOD;
	//2 ^ (MOD-2) = 500000004
	res = (res * 500000004) % MOD;
	return res;
}

ll subsetSeriesSum(ll start, ll end){
	return (seriesSum(end) - seriesSum(start) + MOD) % MOD;
}

int main(){
	ll n;
	cin >> n;
	ll a = 1, res = 0;

	while(a <= n){
		ll temp = n / a, c = n / temp + 1;
		res = (res + ((subsetSeriesSum(a, c) * temp) % MOD)) % MOD;
		a = c;
	}

	cout << res;
	return 0;
}