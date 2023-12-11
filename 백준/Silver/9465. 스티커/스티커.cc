#include <iostream>
using namespace std;

int t, n, answer;
int field[100001][3], dp[100001][3];

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> t;
  
  while(t--) {
    cin >> n;
    
    for(int j = 1; j <= 2; j++) {
      for(int i = 1; i <= n; i++) {
        cin >> field[i][j];
      }
    }
    
    dp[1][1] = field[1][1];
    dp[1][2] = field[1][2];
    
    for(int i = 2; i <= n; i++) {
      for(int j = 1; j <= 2; j++) {
        
        if (j == 1) {
          dp[i][j] = max(dp[i - 1][2], dp[i - 2][2]) + field[i][j];
        } else {
          dp[i][j] = max(dp[i - 1][1], dp[i - 2][1]) + field[i][j];
        }
        
        answer = max(dp[i][j], answer);
      }
    }
    cout << max(dp[n][1], dp[n][2]) << '\n';
  }
  
  return 0;
}