#include <iostream>
using namespace std;
int n;
int s[] = {1, 1, 2, 2, 2, 8};

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  for(int i = 0; i < 6; i++) {
    cin >> n;
    cout << s[i] - n << ' ';
  }
  
  return 0;
}