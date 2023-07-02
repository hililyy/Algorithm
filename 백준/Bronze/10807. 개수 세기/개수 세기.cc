#include <iostream>
#include <cstdlib>
using namespace std;

int main()  {
  int n, m;
  int arr[101] = { 0 };
  int m_arr[101] = { 0 };
  
  cin >> n;
  
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if(a < 0) {
      a = abs(a);
      m_arr[a]++;
    } else {
      arr[a]++;
    }
  }

  cin >> m;
  
  if(m < 0) {
    m = abs(m);
    cout << m_arr[m];
    return 0;
  } else {
      cout << arr[m];
  }
  
  return 0;
}