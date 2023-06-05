#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int field[501][501] = { 0 };
bool is_visited[501][501] = { 0 };
int n, m;
int x_arr[4] = {0, 0, -1, 1};
int y_arr[4] = {-1, 1, 0, 0};
int area_count = 0;
int max_area = 0;

int bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    int area = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int t = 0; t < 4; t++) {
            int xx = x_arr[t] + x;
            int yy = y_arr[t] + y;
            if (xx < 0 || yy < 0 || x >= n || y >=m) continue;
            if (field[xx][yy] && !is_visited[xx][yy]) {
                is_visited[xx][yy] = true;
                area++;
                q.push({xx, yy});
            }
        }
    }
    return area;
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (!is_visited[i][j] && field[i][j]) {
                is_visited[i][j] = true;
                area_count++;
                max_area = max(max_area, bfs(i, j));
            }
        }
    }
    
    cout << area_count << '\n' << max_area;
    return 0;
}
