#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int field[1001][1001] = { 0 };
queue<pair<int, int>> q;
int x_arr[4] = {0 ,0, -1, 1};
int y_arr[4] = {1, -1, 0, 0};
int max_day = 0;

void bfs() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int t = 0; t < 4; t++) {
            int xx = x + x_arr[t];
            int yy = y + y_arr[t];
            
            if(xx < 0 || yy < 0 || xx >= m || yy >= n || field[xx][yy] != 0) continue;
            
            field[xx][yy] = field[x][y] + 1;
            q.push(make_pair(xx, yy));
        }
    }
}

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> field[i][j];
            if(field[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }
    
    bfs();
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(field[i][j] == 0) { 
                cout << "-1"; 
                return 0;
            }
            max_day = max(max_day, field[i][j]);
        }
    }
    
    if(max_day == 1) { 
        cout << "0"; 
        return 0; 
    }
     cout << max_day - 1;
     return 0;
}