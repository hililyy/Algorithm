#include <iostream>
using namespace std;

int n, dp[1001];

int main()  {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  dp[1] = 1;
  dp[2] = 3;
  
  cin >> n;
  
  for(int i = 3; i <= n; i++) {
    dp[i] = ((dp[i - 2] * 2) + dp[i - 1]) % 10007;
  }
  
  cout << dp[n];
  
  return 0;
}