#include <iostream>
#include <string.h>
using namespace std;
int M, N, K; // 가로, 세로, 위치개수
int field[50][50] = { 0 };
int visited[50][50] = { 0 };
int move_x[4] = {1, -1, 0, 0}; //동서남북
int move_y[4] = {0, 0, -1, 1};
void dfs(int x, int y) {
	for (int t = 0; t < 4; t++) {
		int xx = move_x[t] + x;
		int yy = move_y[t] + y;
		if (xx < 0 || xx >= M || yy < 0 || yy >= N) continue; // 필드를 벗어났을 경우
		if (field[xx][yy] && !visited[xx][yy]) {
			visited[xx][yy]++;
			dfs(xx, yy);
		}
	}
}
int main() {
	int T; // 테스트 케이스 개수
	
	int x, y;
	int answer = 0;
	cin >> T;
	for (int test_cast = 0; test_cast < T; test_cast++) {
		cin >> M >> N >> K;
		answer = 0;
		memset(visited, 0, sizeof(visited));
		memset(field, 0, sizeof(field));

		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			field[x][y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && field[i][j]) { // 방문하지 않았고, 필드에 배추가 심어져있음
					answer++;
					visited[i][j]++;
					dfs(i, j);
				}
			}
		}
		cout << answer << '\n';
	}


}