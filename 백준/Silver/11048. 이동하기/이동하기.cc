#include <iostream>
using namespace std;
int n, m;
int field[1001][1001], dp[1001][1001];

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n >> m;
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> field[i][j];
      if(i == 1) dp[1][j] = dp[i][j-1] + field[i][j];
    }
  }
  
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + field[i][j];
    }
  }
  
  cout << dp[n][m];
  
  return 0;
}