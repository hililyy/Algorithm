#include <iostream>
#include <string.h>
using namespace std;
int n, m;
int field[52][52] = { 0 };
bool visited[52][52] = { 0 };
int move_x[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int move_y[8] = {0, 0, 1, -1, 1, -1, 1, -1};
void dfs(int y, int x) {
    for(int t = 0; t < 8; t++) {
        int xx = move_x[t] + x;
        int yy = move_y[t] + y;
        
        if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
        if (field[yy][xx] && !visited[yy][xx]) {
            visited[yy][xx] = true;
            dfs(yy, xx);
        }
    }
}
int main() {
    
    int answer = 0;
    
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    while (true) {
        cin >> m >> n;
        if (n == 0 && m == 0) {
            break;
        }
        
        answer = 0;
        memset(visited, false ,sizeof(visited));
        memset(field, 0, sizeof(field));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> field[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && field[i][j]) {
                    answer++;
                    visited[i][j] = true;
                    dfs(i, j);
                }
            }
        }
        
        cout << answer << '\n';
        
    }
    return 0;
}