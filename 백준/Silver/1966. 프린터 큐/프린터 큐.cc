#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
  int t;
  cin >> t;
  
  for(int i = 0; i < t; i++) {
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
      docs[doc]++;
      q.push({doc, j}); // 문서 중요도, id
    }
    
    for(int k = 9; k > 0; k--) {
      int now; // 현재 가장 중요한 문서의 중요도 
      
      if(docs[k]) {
        now = k;
        docs[k]--;
        k++;
      } else continue; // 현재 가장 중요한 문서의 중요도를 구함
      
      while(flag) {
        if(q.front().first < now) { // 뒤에 더 중요한 문서가 있는 경우
          pair<int, int> front = q.front();
          q.pop();
          q.push(front);
        } else if(now == target_num && q.front().second == target) { // 찾으려는 문서인 경우 (id 일치)
          count++;
          cout << count << endl;
          flag = false;
          break;
        } else if(now != target_num && q.front().first >= now) { // 찾으려는 문서의 중요도만 같은 경우 (id는 불일치) 
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