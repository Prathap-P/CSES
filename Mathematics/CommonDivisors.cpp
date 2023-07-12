#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

#define ll long long

int main(){

	int count;
	cin >> count;

	const int MAX = 1e6;
	vector<int> inputNumbers(MAX+1, 0);

	while(count--){
		ll a;
		cin >> a;
		inputNumbers[a] += 1;
	}

	for(int i = MAX; i >= 2; i--){
		int canBeCommon = 0;
		for(int j = i; j <= MAX; j+=i)
			if(inputNumbers[j] > 0){
				canBeCommon += inputNumbers[j];
				if(canBeCommon > 1){
					cout << i;
					return 0;
				}
			}
	}
	cout << 1;		
	return 0;
}