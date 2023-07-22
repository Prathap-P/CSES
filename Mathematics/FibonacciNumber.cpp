#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;

struct Matrix{
	ll a, b, c, d;
};

Matrix matMul(Matrix matA, Matrix matB){
	Matrix res;
	res.a = (matA.a * matB.a % MOD + matA.b * matB.c % MOD) % MOD;
	res.b = (matA.a * matB.b % MOD + matA.b * matB.d % MOD) % MOD;
	res.c = (matA.c * matB.a % MOD + matA.d * matB.c % MOD) % MOD;
	res.d = (matA.c * matB.b % MOD + matA.d * matB.d % MOD) % MOD;
	return res;
}

Matrix modExpo(Matrix a, ll b){
	if(b == 1)return a;
	Matrix res = modExpo(a, b/2);
	res = matMul(res, res);
	if(b%2)
		res = matMul(res, a);
	return res;
}

int main(){

	ll n;
	cin >> n;

	if(n <= 1){
		cout << n;
		return 0;
	}

	// Fn = F(n-1) + F(n-2)
	// (1 1) (F1) = Fn
	// (1 0) (F0) = Fn-1

	Matrix start;
	start.a = 1;
	start.b = 1;
	start.c = 1;
	start.d = 0;

	Matrix res = modExpo(start, n-1);
	cout << res.a % MOD;

	return 0;
}