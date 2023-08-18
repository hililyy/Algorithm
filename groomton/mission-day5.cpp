#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second; 
	return a.first > b.first;
}

int main() {
	vector <pair <int, int>> v;
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < n; i++) {
		int a, aa;
		int count = 0;
		cin >> a;
		aa = a;
		
		while(a != 0) {
			if ((a % 2) == 1) count ++;
			a /= 2;
		}
		v.push_back({count, aa});
	}
	
	sort(v.begin(), v.end(), compare);
	
	cout << v[k - 1].second;
	
	return 0;
}
