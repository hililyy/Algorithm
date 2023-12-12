#include <iostream>
using namespace std;
int n, sequence[1001], dp[1001], answer;

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n;
  
  for(int i = 1; i <= n; i++) cin >> sequence[i];
  
  for(int i = 1; i <= n; i++) {
    dp[i] = 1;
    
    for(int j= i - 1; j >= 1; j--) {
      if (sequence[i] < sequence[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    answer = max(dp[i], answer);
  }
  
  cout << answer;
  
  return 0;
}