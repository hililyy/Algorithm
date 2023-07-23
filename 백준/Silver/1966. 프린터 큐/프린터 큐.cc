#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
  int t;
  cin >> t;
  
  for(int i=0;i<t;i++) {
    queue<pair<int, int>> q;
    int count = 0;
    int docs[10] = {0};
    int n, target, target_num;
    bool flag = true;
    cin >> n >> target;
    for(int j = 0; j < n; j++) {
      int doc; // 문서 중요도
      cin >> doc;
      
      if(target == j) target_num = doc;
      // cout << "target_num: " << target_num << endl;
      docs[doc]++;
      q.push({doc, j}); // 문서 중요도, id
    }
    // cout << "1: " << q.front().first << "  2: " << q.front().second << " docs[5]: " << docs[5] << endl;
    
    // for(int k=0;k<10;i++) {
      
    // }
    
    for(int k=9;k>0;k--) {
      int now;
      if(docs[k]) {
        now = k;
        // cout << "now: " << now << endl;
        docs[k]--;
        k++;
      } else continue; // 현재 가장 중요한 문서의 중요도를 구함
      // cout << "1: " << q.front().first << "  2: " << now << endl;
      while(flag) {
        if(q.front().first < now) {
          pair<int, int> front = q.front();
          // cout << "1: " << front.first << "  2: " << front.second << endl;
          q.pop();
          q.push(front);
        } else if(now==target_num && q.front().second == target) {
          count++;
          cout << count << endl;
          flag = false;
          break;
        } else if(now!=target_num && q.front().first >= now) {
          q.pop();
          count++;
          break;
        } else {
          q.pop();
          count++;
        }
      }
    }
  }
  return 0;
}
// (1) 1 9 1 1 1
// 1 9 1 1 1 (1)
// 9 1 1 1 (1) 1 
// 1 1 1 (1) 1 // 1
// 1 1 (1) 1 // 2
// 1 (1) 1 // 3
// (1) 1 // 4
// // 5