#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
  return a > b;
}

int main()  {
  int n, k;
  int p[1001] = { 0 };
  cin >> n >> k;
  
  for(int i = 0; i < n; i++) cin >> p[i];

  sort(p, p + n, compare);
  
  cout << p[k - 1];
  
  return 0;
}