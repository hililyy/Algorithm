#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, h;
int field[101][101][101];
queue<pair<pair<int, int>, int>> q;
int x_arr[] = {1, -1, 0, 0, 0, 0,};
int y_arr[] = {0, 0, 1, -1, 0, 0};
int z_arr[] = {0, 0, 0, 0, 1, -1};
int max_day = 0;

void bfs() {
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        
        q.pop();
        
        for(int t = 0; t < 6; t++) {
            int xx = x + x_arr[t];
            int yy = y + y_arr[t];
            int zz = z + z_arr[t];
            
            if(xx < 0 || yy < 0 || zz < 0 || xx >= n || yy >= m || zz >= h || field[xx][yy][zz] != 0) continue;
            
            field[xx][yy][zz] = field[x][y][z] + 1;
            q.push({{xx, yy}, zz});
        }
    }
}

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    cin >> m >> n >> h;
    
    for(int k = 0; k < h; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> field[i][j][k];
                if(field[i][j][k] == 1) {
                    q.push({{i, j}, k});
                }
            }
        }
    }
    
    
    bfs();
    
    for(int k = 0; k < h; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(field[i][j][k] == 0) { 
                cout << "-1"; 
                return 0;
                }
                max_day = max(max_day, field[i][j][k]);
            }
        }
    }
    
    if(max_day == 1) { 
        cout << "0"; 
        return 0; 
    }
     cout << max_day - 1;
     return 0;
}