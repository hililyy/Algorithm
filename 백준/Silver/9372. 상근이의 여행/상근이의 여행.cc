#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  
  for(int i = 0; i < t; i++) {
    int n, m; // 국가의 수, 비행기의 종류
    cin >> n >> m;
    for(int j = 0; j < m; j++) {
      int a, b;
      cin >> a >> b;
    }
    cout << n - 1 << '\n';
  }
  return 0;
}