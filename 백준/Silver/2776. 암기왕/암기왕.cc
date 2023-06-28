#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int num[1000001];

int binary_search(int target, int len) {
  int start = 0;
  int end = len;
  
  while(start <= end) {
    int mid = (start + end) / 2;
    
    if(num[mid] == target ) {
      return 1;
    } else if (num[mid] > target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return 0;
}


int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  int t, n, m;

  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n;
    
    for(int j = 0; j < n; j++) {
      cin >> num[j];
    }
    
    sort(num, num + n);
    cin >> m;
    
    for(int k = 0; k < m; k++) {
      int a;
      cin >> a;
      cout << binary_search(a, n) << '\n';
    }
    memset(num, 0, sizeof(int) * n);
  }
  
  return 0;
}