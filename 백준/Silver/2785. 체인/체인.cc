#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int cnt;
vector<int> v;

int main()  {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n;
  
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  
  sort(v.begin(), v.end());
  
  while(v.size() != 1) {
    v[0]--;
    cnt++;
    
    v[v.size() - 2] += v[v.size() - 1];
    v.pop_back();
    
    if (v[0] == 0) v.erase(v.begin());
  }
  
  cout << cnt;
  
  return 0;
}