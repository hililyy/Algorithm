#include <iostream>
using namespace std;

int main()  {
  int num;
  string str;
  cin >> num;
  
  for(int i=0;i<num;i++) {
      cin >> str;
      cout << str[0] << str[str.length() - 1] << '\n';
  }
  
  return 0;
}