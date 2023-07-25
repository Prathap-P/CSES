#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;

vector<vector<ll>> matMul(vector<vector<ll>> matA, vector<vector<ll>> matB){
	ll n = matA.size(), m = matA[0].size();
	vector<vector<ll>> mul(n, vector<ll>(m));
	for(int i = 0;i < n; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < m; k++)
				mul[i][j] = (mul[i][j] + (matA[i][k] * matB[k][j] % MOD)) % MOD;
	
	return mul;
}

vector<vector<ll>> modExpo(vector<vector<ll>> a, ll b){
	if(b == 1)return a;
	vector<vector<ll>> res = modExpo(a, b/2);
	res = matMul(res, res);
	if(b%2)
		res = matMul(res, a);
	return res;
}

int main(){

	ll n, m, k;
	cin >> n >> m >> k;

	vector<vector<ll>>adj(n, vector<ll>(n, 0));

	while(m){
		ll a, b;
		cin >> a >> b;
		adj[a-1][b-1] += 1;
		--m;
	}

	vector<vector<ll>>res = modExpo(adj, k);

	cout << res[0][n-1];
	return 0;
}