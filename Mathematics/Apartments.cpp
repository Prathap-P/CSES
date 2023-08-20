#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

int main(){

	int n, m, k;
	cin >> n >> m >> k;

	int people[n], aparts[m];

	for(int i = 0; i < n; i++)
		cin >> people[i];

	for(int i = 0; i < m; i++)
		cin >> aparts[i];

	sort(people, people+n);
	sort(aparts, aparts+m);

	int count = 0, j = 0;

	for(int i = 0; i < n; i++){

		while(j < m && aparts[j] < (people[i] - k))
			j++;

		if(j == m)
			break;

		if(aparts[j] <= (people[i] + k)){
			count++;
			j++;
		}

	}	

	cout << count;

	return 0;
}