#include <iostream>
using namespace std;
int n, k; // k: 버틸 수 있는 무게
int weight[100001];
int value[100001];
int dp[101][100001];

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n >> k;
  
  for(int i = 1; i <= n; i++) {
    cin >> weight[i] >> value[i];
  }
  
  for(int limit = 1; limit <= k; limit++) {
    for(int product = 1; product <= n; product++) {
      if(weight[product] > limit) {
        dp[product][limit] = dp[product-1][limit];
      }
      else {
        dp[product][limit] = max(dp[product-1][limit], dp[product-1][limit-weight[product]]+value[product]);
      }
    }
  }
  
  cout << dp[n][k];
  return 0;
}