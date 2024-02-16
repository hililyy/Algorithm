#include <iostream>
using namespace std;

int main() {
  int k, m, n;
  
  cin >> k >> m >> n;
  
  int result = k * m - n;
  
  if(result < 0) cout << 0;
  else cout << result;
  
  return 0;
}