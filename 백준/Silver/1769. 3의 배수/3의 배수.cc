#include <iostream>
#include <cstring>
using namespace std;

int main()  {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
    string n;
    int num = 0;
    int count = 0;
    cin >> n;
    
    while(n.length() > 1) {
      num = 0;
      
      for(int i = 0; i < n.length(); i++) {
        int a = n[i] - '0';
        num += a;
      }
      count++;
      n = to_string(num);
    }
    
    string answer = stoi(n) % 3 == 0 ? "YES" : "NO";
    cout << count << '\n' << answer;
    
    return 0;
}