#include <iostream>
using namespace std;

int main()  {
  int n;
  int answer = 0;
  cin >> n;
  
  for(int i = 0; i < 5; i++){
    int a;
    cin >> a;
    if(n == a) answer++;
  }
  
  cout << answer;
  
  return 0;
}