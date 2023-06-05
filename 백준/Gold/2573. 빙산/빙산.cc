#include <iostream>
#include <cstring>
using namespace std;
int n,m;
bool visited[301][301] = { 0 };
bool sea_visited[301][301] = { 0 };
int field[301][301] = { 0 };
int sea_Field[301][301] = { 0 };
int x_arr[4] = {-1, 1, 0, 0};
int y_arr[4] = {0, 0, 1, -1};
int max_iceberg = 0;
int iceberg = 0;
int answer = 0;
bool is_end = false;
void melt_cnt(int y, int x) {
    for(int t = 0; t < 4; t++) {
        int xx = x_arr[t] + x;
        int yy = y_arr[t] + y;
        
        if(xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
        if(field[yy][xx] == 0 && !sea_visited[yy][xx]) {
            is_end = false;
            sea_Field[y][x]++;
            visited[yy][xx] = true;
        }
    }
}
void dfs(int y, int x) {
    for(int t = 0; t < 4; t++) {
        int xx = x_arr[t] + x;
        int yy = y_arr[t] + y;
        
        if(xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
        if(field[yy][xx] > 0 && !visited[yy][xx]) {
            visited[yy][xx] = true;
            dfs(yy, xx);
        }
    }
}
int main() {
    
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> field[i][j];
            if(max_iceberg < field[i][j]) {
                max_iceberg = field[i][j];
            }
        }
    }
    
    while(!is_end) {
        is_end = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && field[i][j] > 0) {
                    visited[i][j] = true;
                    iceberg++;
                    dfs(i, j);
                }
            }
        }
        if (iceberg >= 2) {
            cout << answer;
            return 0;
        } else {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(field[i][j] > 0) {
                        melt_cnt(i, j);
                    }
                }
            }
            
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                        field[i][j] -= sea_Field[i][j];
                        if (field[i][j] < 0) {
                            field[i][j] = 0;
                        }
                }
            }
            memset(visited, false, sizeof(visited));
            memset(sea_visited, false, sizeof(visited));
            memset(sea_Field, 0, sizeof(sea_Field));
            iceberg = 0;
            answer++;
        }
    }
    
    cout << "0";
    return 0;
}