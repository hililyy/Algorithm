#include <iostream>
using namespace std;

int main() {
  int dp[10001] = { 0 };
  int stairs[10001] = { 0 };
  int n;
  
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> stairs[i];
  }
  
  dp[0] = stairs[0];
  dp[1] = stairs[0] + stairs[1];
  dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
  for(int i = 3; i < n; i++) {
    dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
  }
  
  cout << dp[n - 1];
  
  return 0;
}