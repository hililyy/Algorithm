#include <iostream>
#include <queue>
using namespace std;

int field[100000];
int n, k;
int answer;
queue<int> q;
void bfs(int x, int y) {
    int cnt = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now == k) {  // 동생을 찾았으면
            answer = cnt;
            return;
        }
        
        if(now * 2 <= 100000 && field[now * 2] == 0) {   // 현재 위치 * 2가 필드 최대 크기보다 작고, 방문한 적이 없으면
            field[now * 2] = field[now] + 1; // *2로 순간이동 한 위치는 순간이동 전 위치에서 1초후에 방문 가능
            q.push(now * 2); // 순간이동 한 위치를 다음 탐색할 노드로 추가
            
        }
        
        if(now + 1 <= 100000 && field[now + 1] == 0) {
            field[now + 1] = field[now] + 1;
            q.push(now + 1);
            
        }
        
        if(now - 1 >= 0 && field[now - 1] == 0) {
            field[now - 1] = field[now] + 1;
            q.push(now - 1);
            
        }
        cnt++;
    }
}

int main() {

    cin >> n >> k;
    
    q.push(n);
    field[n] = 1;
    bfs(n, k);
    
    cout << field[k] - 1;
}
