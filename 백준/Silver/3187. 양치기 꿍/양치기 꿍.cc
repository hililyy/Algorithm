#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
char field[251][251] = { 0 };
bool is_visited[251][251] = { 0 };
int x_arr[4] = {0, 0, -1, 1};
int y_arr[4] = {1, -1, 0, 0};
int wolf = 0;
int sheap = 0;
int live_wolf = 0;
int live_sheap = 0;

void dfs(int x, int y) {
    for(int t = 0; t < 4; t++) {
        int xx = x + x_arr[t];
        int yy = y + y_arr[t];
        
        if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
        if(!is_visited[xx][yy] && field[xx][yy] != '#') {
            is_visited[xx][yy] = true;
            
            if(field[xx][yy] == 'v') {
                wolf++;
            } else if(field[xx][yy] == 'k'){
                sheap++;
            }
            
            dfs(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++) {
            field[i][j] = str[j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // v는 늑대, k는 양
            if (!is_visited[i][j] && (field[i][j] == 'v' || field[i][j] == 'k')) {
                if (field[i][j] == 'v') {
                    wolf++;
                } else {
                    sheap++;
                }
                
                is_visited[i][j] = true;
                dfs(i, j);
                
                if(wolf < sheap) {
                    live_sheap += sheap;
                } else {
                    live_wolf += wolf;
                }
                
                wolf = 0;
                sheap = 0;
            }
        }
    }
    
    cout << live_sheap << ' ' << live_wolf;
    return 0;
}
