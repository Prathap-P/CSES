#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll modExponentiation(ll a, ll b){
	if(b == 1)return a;

	ll ans = modExponentiation(a, b/2);
	ans = (ans * ans) % MOD;
	ans = (ans * (b%2 ? a : 1)) % MOD;
	return ans;
}

ll seriesSum(const ll& n){
	return n * (n+1) / 2;
}

ll sumSeries(const pair<ll, ll>& p){
	ll res = modExponentiation(p.first, p.second+1);
	res = (res - 1 + MOD) % MOD;
	res = (res * modExponentiation((p.first - 1), MOD-2)) % MOD;

	return res % MOD;
}

ll divCount(vector<pair<ll, ll>> pairs){
	ll count = 1;
	for(const auto& p : pairs)
		count = (count * ((p.second + 1) % MOD)) % MOD;

	return count;
}


ll sumOfDivs(vector<pair<ll, ll>> pairs){

	ll res = 1;
	for(const auto& p : pairs){
		ll singleAns = sumSeries(p);
		res = (res * singleAns) % MOD;
	}
	return res;
}

ll prodOfDivs(vector<pair<ll, ll>> pairs){
	ll numberOfDivsSoFar = 1, prodRes = 1;

	for(const auto& p : pairs){
		ll combPow = ((seriesSum(p.second) % (MOD-1)) * (numberOfDivsSoFar % (MOD-1))) % (MOD-1);
		ll b = modExponentiation(p.first, combPow);
		ll a = modExponentiation(prodRes, p.second+1);

		prodRes = (a * b) % MOD;
		numberOfDivsSoFar = (numberOfDivsSoFar * ((p.second+1) % (MOD-1))) % (MOD-1);
	}
	return prodRes;
}

int main(){

	int count;
	cin >> count;
	ll number, sum, prod;
	vector<pair<ll, ll>> pairs;

	while(count--){
		ll a, b;
		cin >> a >> b;
		pairs.push_back(make_pair(a, b));
	}

	number = divCount(pairs);
	sum = sumOfDivs(pairs);
	prod = prodOfDivs(pairs);

	cout << number << ' ' << sum << ' ' << prod;

	return 0;
}