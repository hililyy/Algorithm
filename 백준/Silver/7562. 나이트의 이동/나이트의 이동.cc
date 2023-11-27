#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int t, field_length, field[301][301];
int start_x, start_y, goal_x, goal_y;
bool is_visited[301][301];
int wx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int wy[] = {-1, 1, -2, 2, -2, 2,-1, 1};

void reset() {
  while (!q.empty()) q.pop();
  
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			is_visited[i][j] = false;
			field[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {
  q.push({x, y});
  is_visited[x][y] = true;
  
  while(!q.empty()) {
    int front_x = q.front().first;
    int front_y = q.front().second;
    
    q.pop();
    
    if(front_x == goal_x && front_y == goal_y) cout << field[front_x][front_y] << '\n'; 
    
    for(int i = 0; i < 8; i++) {
      int xx = wx[i] + front_x;
      int yy = wy[i] + front_y;
      
      if(xx < 0 || yy < 0 || xx >= field_length || yy >= field_length) continue;
      
      if(!is_visited[xx][yy]) {
        q.push({xx, yy});
        is_visited[xx][yy] = true;
        field[xx][yy] = field[front_x][front_y] + 1;
      }
    }
  }
}

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  cin >> t;
  
  for(int i = 0; i < t; i++) {
    cin >> field_length >> start_x >> start_y >> goal_x >> goal_y;
    bfs(start_x, start_y);
    reset();
  }
  
  return 0;
}