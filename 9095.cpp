#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int dp[12] = { 0 };
	int test[12] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> test[i];
	}

	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 1; i <= n; i++) {
		if (dp[test[i]] == 0) {
			for (int j = 4; j <= test[i]; j++) {
				dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
			}
		}
		cout << dp[test[i]] << endl;
	}
	
}