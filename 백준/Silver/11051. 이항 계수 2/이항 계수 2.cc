#include <iostream>
using namespace std;

int n, k, dp[1001][1001];
long long answer = 1;

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n >> k;
  
  dp[0][0] = 1;
  
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) dp[i][j] = 1;
      else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
    }
  }
  
  cout << dp[n][k];
   
  return 0;
}