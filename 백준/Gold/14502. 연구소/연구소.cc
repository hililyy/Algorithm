#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int field[10][10], c_field[10][10];
bool is_visited[10][10];
int x_arr[] = {0, 0, -1, 1};
int y_arr[] = {-1, 1, 0, 0};
int wall_count = 3;
int answer;

void bfs() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) c_field[i][j] = field[i][j];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            if(c_field[i][j] == 2) {
                queue<pair<int, int>> q;
                q.push({i, j});
                is_visited[i][j] = true;
                
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int t = 0; t < 4; t++) {
                        int xx = x + x_arr[t];
                        int yy = y + y_arr[t];
                        
                        if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                        
                        if(!is_visited[xx][yy] && c_field[xx][yy] == 0) {
                            q.push({xx, yy});
                            is_visited[xx][yy] = true;
                            c_field[xx][yy] = 2;
                        }
                    }
                }
            }
        }
    }
    
    memset(is_visited, false, sizeof(is_visited));
    
    int safe_area = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) if(c_field[i][j] == 0) safe_area++;
        
    answer = max(safe_area, answer);
}

void wall() {
    if(wall_count == 0) return bfs();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(field[i][j] == 0) {
                wall_count--;
                field[i][j] = 1;
                
                wall();
                
                wall_count++;
                field[i][j] = 0;
            }
        }
    }
}

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    
    memset(field, -1, sizeof(field));
    memset(c_field, -1, sizeof(c_field));
    
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) cin >> field[i][j];
    
    wall();
    
    cout << answer << '\n';
    return 0;
}
