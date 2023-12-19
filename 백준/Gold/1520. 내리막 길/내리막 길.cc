#include <iostream>
using namespace std;
int m, n, field[501][501], dp[501][501]; // dp: i,j번째에서 목적지까지 가는 방법 개수 저장
int wx[] = {-1, 1, 0, 0};
int wy[] = {0, 0, -1, 1};

int dfs(int y, int x) {
  if(y == m && x == n) return 1; // 목적지 -> 목적지까지 가는 길은 1개
  
  if(dp[y][x] == -1) {
    dp[y][x] = 0;
  
    for(int i = 0; i < 4; i++) {
      int yy = wy[i] + y;
      int xx = wx[i] + x;
      
      if(yy < 1 || yy > m || xx < 1 || xx > n) continue;
      if(field[y][x] > field[yy][xx]) {
        dp[y][x] += dfs(yy, xx); // 목적 지점을 발견하면 돌아오면서 개수를 더함
      }
    }
  }
  
  return dp[y][x];
}

int main() {
  
  cin >> m >> n;
  
  for(int i = 1; i <= m; i++){ // i -> 세로
    for(int j = 1; j <= n; j++) { // j -> 가로
      cin >> field[i][j];
      dp[i][j] = -1;
    }
  }
  
 cout << dfs(1, 1); // 시작지점 ~ 끝 지점 까지의 거리를 구해야함
 
  return 0;
}