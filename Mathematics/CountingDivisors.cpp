#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

#define ll long long

int main(){

	int count;
	cin >> count;

	const int MAX = 1e6;
	vector<int> divCount(MAX, 1);

	for(int i = 2; i <= MAX; i++)
		for(int j = i; j <= MAX; j += i)
			divCount[j-1]++;

	while(count--){
		ll a;
		cin >> a;
		cout << divCount[a-1] << '\n';
	}

	return 0;
}