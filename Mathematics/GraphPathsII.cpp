#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define ll long long

vector<vector<ll>> matMul(vector<vector<ll>> matA, vector<vector<ll>> matB){
	ll n = matA.size(), m = matA[0].size();
	vector<vector<ll>> mul(n, vector<ll>(m));
	for(int i = 0;i < n; i++)
		for(int j = 0; j < m; j++){
			ll minNum = -1;
			for(int k = 0; k < m; k++){
				if((matA[i][k] == -1) || (matB[k][j] == -1))
					continue;
				if(minNum == -1) minNum = matA[i][k] + matB[k][j];
				else minNum = min(minNum, matA[i][k] + matB[k][j]);
			}
			mul[i][j] = minNum;
		}
	
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

	vector<vector<ll>>adj(n, vector<ll>(n, -1));

	while(m){
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a-1][b-1] = adj[a-1][b-1] == -1 ? c : min(c, adj[a-1][b-1]);
		--m;
	}

	vector<vector<ll>>res = modExpo(adj, k);

	cout << res[0][n-1];
	return 0;
}