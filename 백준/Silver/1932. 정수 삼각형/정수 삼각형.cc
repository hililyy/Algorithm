#include <iostream>
using namespace std;

int n, answer;
int dp[501][501];
int tower[501][501];

int main()  {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
      cin >> tower[i][j];
    }
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tower[i][j];
      answer = max(dp[i][j], answer);
    }
  }
  
  cout << answer;
  
  return 0;
}