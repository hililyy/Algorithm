#include <iostream>
using namespace std;
long long dp[1001][1001], n;

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  
  for(int i=0;i<=9;i++) {
    dp[1][i] = 1;
  }
  
  for(int i=2;i<=n;i++){
    for(int j=0;j<=9;j++) {
      int sum = 0;
      for(int k=j;k<=9;k++) {
        sum += dp[i-1][k];
      }
      dp[i][j] = sum % 10007;
    }
  }
  
  
  // for(int i=0;i<=n;i++){
  //   for(int j=0;j<=9;j++) {
  //     cout << dp[i][j];
  //   }
  //   cout << endl;
  // }
  int answer = 0;
  for(int i=0;i<=9;i++) {
    answer += dp[n][i];
  }
  cout << answer % 10007;
  return 0;
}