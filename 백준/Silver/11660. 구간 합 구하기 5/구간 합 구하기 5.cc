#include <iostream>
using namespace std;
int n, m, field[1025][1025], dp[1025][1025];

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> n >> m;
  
  for(int i = 1; i <= n; i++) {
    int sum = 0;
    
    for(int j = 1; j <= n; j++) {
      int input;
      cin >> input;
      sum += input;
      field[i][j] = field[i-1][j] + sum;
    }
  }
  
  for(int t = 0; t < m; t++) {
    int start_x, start_y, end_x, end_y;
    int answer = 0;
    
    cin >> start_x >> start_y >> end_x >> end_y;
    int total = field[end_x][end_y];
    int margin_x = field[end_x][start_y - 1];
    int margin_y = field[start_x - 1][end_y];
    int overlap = field[start_x - 1][start_y - 1];
    
    answer = total - margin_x - margin_y + overlap;
    cout << answer << '\n';
  }
  
  return 0;
}