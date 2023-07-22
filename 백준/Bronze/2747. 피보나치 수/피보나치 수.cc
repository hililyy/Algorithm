#include <iostream>
using namespace std;

int dp[46] = {0, 1, 1};

int solution(int n) {
    if(n == 0) return 0;
    else if (!dp[n]) 
        dp[n] = solution(n - 1) + solution(n - 2);
    return dp[n];
}

int main() {
  int n;
  cin >> n;
  
  cout << solution(n);
  
  return 0;
}