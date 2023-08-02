#include <iostream>
using namespace std;

int main()  {
  int m, d;
  
  int month[12] = {1, 4, 4, 7, 2, 5, 7, 3, 6, 1, 4, 6};
  string str[10] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  
  cin >> m >> d;
  
  int a = ((d % 7) + month[m - 1] - 1) % 7;
  
  cout << str[a];
  return 0;
}