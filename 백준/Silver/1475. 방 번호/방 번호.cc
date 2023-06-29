#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  int arr[9] = { 0 };
  
  cin >> s;
  
  if(s.length() == 1) {
    cout << '1';
    return 0;
  }
  
  for(int i = 0; i < s.length(); i++) arr[(int)s[i] - 48]++;
  
  int maxium = 0;
  
  for(int i = 0; i <= 9; i++) {
    if (i == 6 || i == 9) continue;
    maxium = max(maxium, arr[i]);
  }
  
  int a = ((arr[6] + arr[9]) % 2) > 0 ? (arr[6] + arr[9]) / 2 + 1 : (arr[6] + arr[9]) / 2;
  
  cout << max(maxium, a);
  
  return 0;
}