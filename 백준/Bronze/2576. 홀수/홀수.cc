#include <iostream>
using namespace std;

int main() {
  int minimum = 101;
  int sum = 0;
  
  for(int i = 0; i < 7; i++) {
    int n;
    cin >> n;
    
    if(n % 2 == 1) {
      sum += n;
      minimum = min(minimum, n);
    }
  }
  
  if(sum == 0) {
    cout << -1;
  } else {
    cout << sum << '\n' << minimum;
  }
  
  return 0;
}