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

	string str;
	getline(cin, str);
	int arr[26] = {0};

	for(char c : str)
		arr[c-'a']++;

	ll res = fact(str.size());

	for(int i = 0; i < 26; i++){
		ll temp = fact(arr[i]);
		temp = modExpo(temp, MOD-2);
		res = res * temp % MOD;
	}

	cout << res;
	return 0;
}