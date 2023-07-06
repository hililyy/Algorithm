#include <iostream>
using namespace std;
int main()  {
    
  int a, b, c;
  int year = 1;
  
  cin >> a >> b >> c;

  while(true) {
    if(((year - a) % 15 == 0) && ((year - b) % 28 == 0) && ((year - c) % 19 == 0)) {
      cout << year;
      return 0;
    }
    year++;
  }
  
    return 0;
}