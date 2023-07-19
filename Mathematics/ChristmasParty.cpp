#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;

int main(){

	int n;
	cin >> n;

	vector<ll> dp(n+1);
	dp[1] = 0;
	dp[2] = 1;

	for(int i = 3; i <= n; i++)
		dp[i] = (dp[i-1] + dp[i-2]) % MOD * (i-1) % MOD;

	cout << dp[n];
	return 0;
}
