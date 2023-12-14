#include <iostream>
using namespace std;
string f, s;
int lcs[1001][1001], answer;

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> f >> s;
  
  for(int i = 1; i <= f.length(); i++) {
    for(int j = 1; j <= s.length(); j++) {
      if(f[i - 1] == s[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
      else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]); 
      
      answer = max(answer, lcs[i][j]);
    }
  }
  cout << answer; 
  
  return 0;
}