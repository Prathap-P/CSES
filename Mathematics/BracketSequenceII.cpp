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
	string str;
	cin >> n >> str;

	if(n%2){
		cout << 0;
		return 0;
	}

	ll open = 0, close = 0;
	vector<char> stack;
	for (int i = 0; i < str.length(); ++i){
		str[i] == '(' ? ++open : ++close;
		if(str[i] == '(')
			stack.push_back('(');
		else if(!stack.empty())
			stack.pop_back();
		else{
			cout << 0;
			return 0;
		}
	}

	n /= 2;	
	if(open > n){
		cout << 0;
		return 0;
	}

	ll k = open - close;
	n -= open;

	// (2n+k)! / (n! * (n+k)!) --- All arrangements
	ll  twoNplusK= fact((2 * n % MOD + k) % MOD), nFact = fact(n), nPlusK = fact((n + k) % MOD);
	ll a = twoNplusK * modExpo(nFact, MOD-2) % MOD * modExpo(nPlusK, MOD-2) % MOD; 

	// (2n+k)! / ((n-1)! * (n+k+1)!) --- Bad arrangements
	ll  nMinus1 = nFact * modExpo(n, MOD-2) % MOD, nPlusKplus1 = ((n + k) % MOD + 1) % MOD * nPlusK % MOD;
	ll b = twoNplusK * modExpo(nMinus1, MOD-2) % MOD * modExpo(nPlusKplus1, MOD-2) % MOD; 

	cout << (a - b + MOD) % MOD;
	return 0;
}