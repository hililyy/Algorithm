#include <iostream>
using namespace std;

int n, card, dp[10001];

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n;
  cin >> dp[1];
  
  for(int i = 2; i <= n; i++) {
    cin >> dp[i];
    
    for(int j = i-1; j >= 1; j--) {
      dp[i] = max(dp[i], dp[j] + dp[i - j]);
    }
  }
  
  cout << dp[n];
  
  return 0;
}