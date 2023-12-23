#include <iostream>
using namespace std;
long long n, dp_a[1001], dp_b[1001];

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n;
  
  dp_a[0] = 1;
  dp_b[1] = 1;
  
  for(int i = 2; i <= n; i++){
    dp_a[i] = dp_b[i - 1];
    dp_b[i] = dp_a[i - 1] + dp_b[i - 1];
  }
  
  cout << dp_a[n] << ' ' << dp_b[n];
  
  return 0;
}