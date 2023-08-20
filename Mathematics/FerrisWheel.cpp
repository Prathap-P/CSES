#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	
	int n, x;
	cin >> n >> x;
	
	vector<int> weights(n);

	for(int i = 0; i < n; i++)
		cin >> weights[i];

	std::sort(weights.begin(), weights.end());

	int ans = 0, i = 0, j = n-1;
	while(i < j){
		if((weights[i] + weights[j]) <= x)
			i++;

		ans++;
		j--;
	}

	ans += (i == j) ? 1 : 0;
	cout << ans;

	return 0;
}