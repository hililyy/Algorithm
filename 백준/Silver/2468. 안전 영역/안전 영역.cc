#include <iostream>
#include <cstring>
using namespace std;

#define MAX_HEIGHT 100
#define MIN_HEIGHT 2
bool visited[100][100];
int field[100][100];
int n, safe_num;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void init() {
	safe_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}

void dfs(int x, int y, int height) {
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;    // 영역을 벗어나면 continue
        if(!visited[nx][ny] && field[nx][ny] > height) dfs(nx, ny, height);    // 방문하지 않은 안전지역이면 
    }
}

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    int answer = 0;
    int max = MIN_HEIGHT, min = MAX_HEIGHT;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> field[i][j];
            if(max < field[i][j]) max = field[i][j];
            else if(min > field[i][j]) min = field[i][j];
        }  
    }
    
    for(int height = min - 1; height <= max; height++) {
        init();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && field[i][j] > height) {    // 방문하지 않았고, 안전지역이면
                    safe_num++;
                    dfs(i, j, height);
                }
            }
        }
        if(answer < safe_num) answer = safe_num;
    }
    cout << answer;
}
