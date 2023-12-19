#include <iostream>
using namespace std;
int m, n, field[501][501], dp[501][501];
int wx[] = {-1, 1, 0, 0};
int wy[] = {0, 0, -1, 1};

int dfs(int y, int x) {
  if(y == m && x == n) return 1;
  
  if(dp[y][x] != -1) return dp[y][x];
  dp[y][x] = 0;
  
  for(int i = 0; i < 4; i++) {
    int yy = wy[i] + y;
    int xx = wx[i] + x;
    // cout << "xx: " << xx << " yy: " << yy << endl;
    
    if(yy < 1 || yy > m || xx < 1 || xx > n) continue;
    if(field[y][x] > field[yy][xx]) {
      // cout << "1 : " << field[y][x] << " " << " 2 : " << field[yy][xx] << endl; 
      int answer = dfs(yy, xx);
      // cout << "y: " << y << " x: " << x << " a: " << answer << endl;
      dp[y][x] += answer;
    }
  }
  return dp[y][x];
}

int main() {
  
  cin >> m >> n;
  
  for(int i=1;i<=m;i++){ // i -> 세로
    for(int j=1;j<=n;j++) { // j -> 가로
      cin >> field[i][j];
      dp[i][j] = -1;
    }
  }
  
 cout << dfs(1, 1)<<endl;
  
  // for(int i = 1; i <= m; i++){ // i -> 세로
  //   for(int j = 1; j <= n; j++) { // j -> 가로
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  
  return 0;
}