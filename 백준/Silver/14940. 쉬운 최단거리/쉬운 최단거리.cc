#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool is_visited[1001][1001];
int field[1001][1001];
int n, m;
int x_arr[] = {0, 0, -1, 1};
int y_arr[] = {1, -1, 0, 0};
queue<pair<int, int>> q;

void bfs() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
    
        q.pop();
        
        for(int t = 0; t < 4; t++) {
            int xx = x_arr[t] + x;
            int yy = y_arr[t] + y;
            
            if(xx < 0 || yy < 0 || yy >= m || xx >= n) continue;
            if(!is_visited[xx][yy]) {
                field[xx][yy] = field[x][y] + 1;
                is_visited[xx][yy] = true;
                q.push({xx,yy});
            }
        }
    }
}

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> field[i][j];
            if(field[i][j] == 2) {
                field[i][j] = 0;
                q.push({i, j});
                is_visited[i][j] = true;
            } else if (field[i][j] == 0) {
                is_visited[i][j] = true;
            }
        }
    }
    
    bfs();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!is_visited[i][j]) {
                cout << "-1 ";
            } else {
                cout << field[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}
