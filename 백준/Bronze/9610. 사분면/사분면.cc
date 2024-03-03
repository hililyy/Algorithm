#include <iostream>
using namespace std;

int main() {
  int n;
  int q1 = 0, q2 = 0, q3 = 0, q4 = 0, axis = 0;
  cin >> n;
  
  for(int i=0;i<n;i++) {
    int a, b;
    cin >> a >> b;
    if(a == 0 || b == 0) axis++;
    else if (a > 0 && b > 0) q1++;
    else if (a < 0 && b > 0) q2++;
    else if (a < 0 && b < 0) q3++;
    else q4++;
  }
  
  cout << "Q1: " << q1 << '\n';
  cout << "Q2: " << q2 << '\n';
  cout << "Q3: " << q3 << '\n';
  cout << "Q4: " << q4 << '\n';
  cout << "AXIS: " << axis << '\n';
    
  return 0;
}