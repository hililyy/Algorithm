#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,_n; // input
	long long dp[1000001] = { 0 };
	
	cin >> n;
	_n = n;

	while (--n) {
		if (_n/2 < n) {
			dp[n] = dp[n+1] + 1;
		}
		else if (_n/2 >= n && _n/3 < n) {
			dp[n] = min(dp[n + 1], dp[n * 2]) + 1;
		}
		else {
			dp[n] = min({ dp[n + 1], dp[n * 2], dp[n * 3] }) + 1;
		}
	}
	cout << dp[1];
}