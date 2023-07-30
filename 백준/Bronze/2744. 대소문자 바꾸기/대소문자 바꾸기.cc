#include <iostream>
using namespace std;

int main()  {
  string s;
  cin >> s;
  
  for(int i = 0; i < s.length(); i++) s[i] = s[i] >= 'A' && s[i] <= 'Z' ? s[i] += 32 : s[i] -= 32;
  
  cout << s;
  
  return 0;
}