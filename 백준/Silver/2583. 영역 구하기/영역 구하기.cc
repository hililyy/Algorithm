#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m ,k, cnt;
bool is_visited[101][101];
bool field[101][101];
int x_arr[] = {0, 0, -1, 1};
int y_arr[] = {1, -1, 0, 0};
vector<int> v;

int bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    int area = 1;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int t=0;t<4;t++) {
            int xx = x + x_arr[t];
            int yy = y + y_arr[t];
            
            if(xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
            if(!is_visited[xx][yy] && !field[xx][yy]) {
                is_visited[xx][yy] = true;
                area++;
                q.push({xx, yy});
            }
        }
    }
    return area;
}

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    cin >> m >> n >> k;
    
    for(int a=0;a<k; a++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i >= y1 && i < y2 && j >= x1 && j < x2) field[i][j] = true;
            }
        }
    }
    
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(!is_visited[i][j] && !field[i][j]) {
                cnt++;
                is_visited[i][j] = true;
                v.push_back(bfs(i, j));
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    cout << cnt << '\n';
    
    for(int i: v) {
        cout << i << ' ';
    }
    
    return 0;
}
