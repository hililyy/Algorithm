#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> line[501];
int dp[501], maximum, n; 

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n;
  
  for(int i = 0; i < n; i++) cin >> line[i].first >> line[i].second;
  
  sort(line, line + n);
  
  dp[0] = 1;
  
  for(int i = 1; i < n; i++) {
    dp[i] = 1;
    
    for(int j = i - 1; j >= 0; j--) {
      if(line[i].second > line[j].second) dp[i] = max(dp[i], dp[j] + 1);
    }
    
    maximum = max(dp[i], maximum);
  }
  
  cout << n - maximum;
  
  return 0;
}