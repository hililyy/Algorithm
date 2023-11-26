#include <iostream>
#include <cmath>
using namespace std;

bool field[101][101];
bool is_visited[101][101];
int n, m, k, max_count, count;
int wx[4] = {-1, 1, 0, 0};
int wy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
  count++;
  is_visited[x][y] = true;
  for(int i = 0; i < 4; i++) {
    int xx = x + wx[i];
    int yy = y + wy[i];
    if(xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
    if(!is_visited[xx][yy] && field[xx][yy]) dfs(xx,yy);
  }
}

int main()  {
  cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> k;
  
  for(int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    field[x][y] = true;
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      count = 0;
      if(!is_visited[i][j] && field[i][j]) {
        dfs(i, j);
        max_count = max(max_count, count);
      }
    }
  }
  
  cout << max_count;
  return 0;
}