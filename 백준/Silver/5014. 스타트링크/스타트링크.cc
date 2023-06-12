#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool is_visited[1000001];
int max_floor, start, goal, up_floor, down_floor;
bool flag;
queue<pair<int, int>> q;

void bfs() {
    while(!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(is_visited[now]) continue;
        
        is_visited[now] = true;
        
        if(now == goal) {
            cout << cnt;
            flag = true;
            return;
        }
        
        if(now + up_floor <= max_floor && !is_visited[now + up_floor]) {
            q.push({now + up_floor, cnt + 1});
        }
        if(now - down_floor >= 0 && !is_visited[now - down_floor]) {
            q.push({now - down_floor, cnt + 1});
        }
    }
}

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    cin >> max_floor >> start >> goal >> up_floor >> down_floor;
    
    is_visited[0] = true;
    q.push({start, 0});
    
    bfs();
    
    if (!flag) {
        cout << "use the stairs";
    }
    return 0;
}