#include <iostream>
using namespace std;
int n;
int s[10001], dp[10001];

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n;
  
  for(int i = 1; i <= n; i++) cin >> s[i];
  
  dp[1] = s[1];
  dp[2] = s[1] + s[2];
  
  for(int i = 3; i <= n; i++) {
    dp[i] = max(s[i] + dp[i - 2], max(dp[i - 1], s[i] + s[i - 1] + dp[i - 3]));
  }
  
  cout << dp[n];
  
  return 0;
}