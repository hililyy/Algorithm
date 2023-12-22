#include <iostream>
using namespace std;
long long n, dp[100001];

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n;
  dp[0] = 1;
  dp[1] = 3;
  
  for(int i = 2; i <= n; i++){
    dp[i] = ((dp[i - 2] * 3) + (dp[i - 1] - dp[i - 2]) * 2) % 9901;
  }
  
  cout << dp[n];
  
  return 0;
}