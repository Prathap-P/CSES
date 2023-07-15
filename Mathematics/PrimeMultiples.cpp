#include<iostream>
#include<vector>
using namespace std;

#define ll long long

ll ans = 0;

void func(vector<ll> primes, int index, double primeMuls, ll primeCounts, ll n){
	if(index == (int)primes.size()){
		if(primeCounts == 0) return;
		ll countsOfCurrComb = n / (ll)primeMuls;
		if(primeCounts%2){
			ans += countsOfCurrComb;
		}
		else{
			ans -= countsOfCurrComb;
		}
		return;
	}

	func(primes, index+1, primeMuls, primeCounts, n);
	primeMuls *= primes[index];
	if(primeMuls > n)return;

	func(primes, index+1, primeMuls, primeCounts+1, n);
}

int main(){

	ll n, k;
	cin >> n >> k;

	vector<ll> primes(k);
	for(int i = 0; i < k; i++)
		cin >> primes[i];

	func(primes, 0, 1, 0, n);
	cout << ans;

	return 0;
}