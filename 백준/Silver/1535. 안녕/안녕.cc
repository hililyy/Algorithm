#include <iostream>
using namespace std;
int n;
int health[100001];
int delight[100001];
int dp[101][21];

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n;
  
  for(int i = 1; i <= n; i++) cin >> health[i];
  for(int i = 1; i <= n; i++) cin >> delight[i];
  
  for(int hp = 0; hp <= 99; hp++) {
    for(int j = 1; j <= n; j++) {
      if(health[j] > hp) {
        dp[hp][j] = dp[hp][j-1];
      }
      else {
        dp[hp][j] = max(dp[hp][j - 1], dp[hp - health[j]][j - 1] + delight[j]);
      }
    }
  }
  
  cout << dp[99][n];
  return 0;
}