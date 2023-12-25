#include <iostream>
using namespace std;
int n;
bool s[31] = { 0 };

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  for(int i = 0; i < 28; i++) {
    cin >> n;
    s[n] = true;
  }
  
  for(int i = 1; i <= 30; i++) {
    if(!s[i]) cout << i << '\n';
  }
  
  return 0;
}