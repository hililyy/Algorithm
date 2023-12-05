#include <iostream>
using namespace std;

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  int n;
  int maxium = -100001;
  int answer = -100001;
  
  cin >> n;
  
  for(int i = 0; i < n; i++) {
    int input;
    cin >> input;
    
    if(maxium + input < input) maxium = input;
    else maxium = maxium + input;
    answer = max(answer, maxium);
  }
  
  cout << answer;
  
  return 0;
}