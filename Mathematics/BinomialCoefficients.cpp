#include<iostream>
#include<cmath>
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

vector<ll> generateFactorials(ll limit){
	vector<ll> factorials(limit+1, 1);
	for(int i = 1; i<= limit; i++)
		factorials[i] = (factorials[i-1] * i) % MOD;
	return factorials;
}

int main(){

	int count;
	cin >> count;
	vector<ll> factorials = generateFactorials(1e6);

	while(count--){
		ll a, b;
		cin >> a >> b;

		ll factA = factorials[a], factB = factorials[b], factDiff = factorials[a-b];
		ll factBInv = modExpo(factB, MOD-2), factDiffInv = modExpo(factDiff, MOD-2);
		ll res = factA * factBInv % MOD * factDiffInv % MOD;

		cout << res << "\n";
	}

	return 0;
}