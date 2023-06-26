#include <iostream>
#include <algorithm>
using namespace std;

int card[500001];

bool binary_search(int target, int len) {
  int start = 0;
  int end = len;
  while(start <= end) {
    int mid = (start + end) / 2;
    
    if(card[mid] == target) return true;
    else if(card[mid] > target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return false;
}

int main(){
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
  int n, m;
  cin >> n;
  
  for(int i = 0; i < n; i++) {
    cin >> card[i];
  }
  
  sort(card, card + n);
  
  cin >> m;
  
  for(int i = 0; i < m; i++) {
    int a;
    cin >> a;
    if (binary_search(a, n)) {
      cout << '1' << ' ';
    } else { 
      cout << '0' << ' ';
    }
  }
    
  return 0;
}