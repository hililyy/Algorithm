#include <iostream>
using namespace std;

int solution(int n) {
  int answer = 0;
  
  while(n > 0) {
    if(n % 5 == 0) {
      answer += n / 5;
      n = n % 5;
    } else {
      n -= 2;
      if(n < 0) return -1;
      answer++;
    }
  }
  return answer;
}

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  int n;
  cin >> n;
  cout << solution(n);
  
  return 0;
}
