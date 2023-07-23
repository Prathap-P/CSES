#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;

vector<vector<ll>> matMul(vector<vector<ll>> matA, vector<vector<ll>> matB){
	vector<vector<ll>> mul(6, vector<ll>(6));
	for(int i = 0;i < 6; i++)
		for(int j = 0; j < 6; j++)
			for(int k = 0; k < 6; k++){
				ll res = matA[i][k] * matB[k][j] % MOD;
				mul[i][j] = (mul[i][j] + res) % MOD;
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

	ll n;
	cin >> n;

	// Fn = F(n-1) + F(n-2) + F(n-3) + F(n-4) + F(n-5) + F(n-6)
	// A = X * B;
	// (6, 1) = (6 * 6) * (6 * 1)
	// X = (1 1 1 1 1 1)
	//     (1 0 0 0 0 0)
	//     (0 1 0 0 0 0)
	//     (0 0 1 0 0 0)
	//     (0 0 0 1 0 0)
	//     (0 0 0 0 1 0)
	vector<vector<ll>> initial = {
		{1, 1, 1, 1, 1, 1},
	    {1, 0, 0, 0, 0, 0},
	    {0, 1, 0, 0, 0, 0},
	    {0, 0, 1, 0, 0, 0},
	   	{0, 0, 0, 1, 0, 0},
	    {0, 0, 0, 0, 1, 0},
	};


	vector<vector<ll>> res = modExpo(initial, n);
	cout << res[0][0];

	return 0;
}