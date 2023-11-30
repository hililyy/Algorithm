#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l,answer;
int leaks[1001];
vector<int> leaks_continue_count;

int main() {
  cin >> n >> l;
  
  for(int i = 0; i < n; i++)  {
    cin >> leaks[i];
  }
  
  sort(leaks, leaks + n);
  
  int front = leaks[0];
  int continue_count = 1;
  
  for(int i = 1; i < n; i++) {
    if(l <= leaks[i] - front) {
      answer++;
      front = leaks[i];
    }
  }
  
  cout << answer + 1;
  
  return 0;
}