#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  string s[51];
  cin >> n;
  
  for(int i = 0; i < n; i++) cin >> s[i];
  
  for(int i = 0; i < s[0].length(); i++) {
    char a = s[0][i];
    for(int j = 0; j < n; j++) if(a != s[j][i]) a = '?';
    cout << a;
  }
  
  return 0;
}