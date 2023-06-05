#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
bool is_visited[101][101] = { 0 };
bool field[101][101] = { 0 };
int road_count[101][101] = { 0 };
int x_arr[4] = {0 ,0, -1, 1};
int y_arr[4] = {1, -1, 0, 0};

void bfs(int i, int j) {
    is_visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    road_count[i][j]++;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int t = 0; t < 4; t++) {
            int xx = x + x_arr[t];
            int yy = y + y_arr[t];
            
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            
            if (!is_visited[xx][yy] && field[xx][yy]) {
                is_visited[xx][yy] = true;
                road_count[xx][yy] = road_count[x][y] + 1;
                q.push(make_pair(xx, yy));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++) {
            field[i][j] = str[j] - '0';
        }
    }
    
    bfs(0, 0);
    
    cout << road_count[n-1][m-1];
}
