#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  int t, n, m;
  ll result;
  cin >> t;
  
  for(int i = 0; i < t; i++) {
    cin >> n >> m;
    
    int r = 1;
    result = 1;
    
    for(int j = m; j > m - n; j--) {
      result = result * j;
      result = result / r;
      r++;
    }
    cout << result << '\n';
  }
  return 0;
}