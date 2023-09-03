#include <iostream>
using namespace std;

int dp[1000001];

int main() {
	cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
	
	int N, A, B;
	
	cin >> N >> A >> B;

	dp[A] = dp[B] = 1;
	
	for(int i = A + 1; i <= N; i++) {
		if(i <= B) {
			if(dp[i - A]) dp[i] = dp[i - A] + 1;
			continue;
		}
		
		dp[i] = min(dp[i - A], dp[i - B]);
		dp[i] = dp[i] ? dp[i] : max(dp[i - A], dp[i - B]);
		
		if(dp[i]) dp[i]++;
	}
	
	if(dp[N]) cout << dp[N];
	else cout << -1;
	
	return 0;
}
