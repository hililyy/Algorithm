#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int n,T;
	long long dp[102] = { 0 };
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	cin >> T;
	
	for(int i = 0; i < T; i++) {
		cin >> n;
		if (dp[n] == 0) {
			for (int j = 4; j <= n; j++) {
				if (dp[j] == 0) {
					dp[j] = dp[j - 3] + dp[j - 2];
				}
			}
		}
		cout << dp[n] << '\n';
 	}
}