#include <iostream>
using namespace std;

int n, dp[10001];

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n;
  
  for(int i = 1; i <= n; i++) {
    cin >> dp[i];
    
    for(int j = i - 1; j >= i / 2; j--) {
      dp[i] = max(dp[i], dp[j] + dp[i - j]);
    }
  }
  
  cout << dp[n];
  
  return 0;
}