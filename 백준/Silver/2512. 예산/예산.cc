#include <iostream>
#include <algorithm>
using namespace std;

int country[100001];

int main()  {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  int n, total, start, end;
  int answer = 0;
    
  cin >> n;
  
  for(int i = 0; i < n; i++) {
    cin >> country[i];
  }
  
  sort(country, country + n);
  
  cin >> total;
  
  start = 0;
  end = country[n-1];
  
  while(start <= end) {
    int sum = 0;
    int mid = (start + end) / 2;
    
    for(int i=0;i<n;i++){
      sum += min(country[i], mid);
    }
      
    if(total >= sum) {
      answer = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
    
  cout << answer;
  return 0;
}