#include <iostream>
#include <algorithm>
using namespace std;
int n;
int answers = 1;
char field[25][25] = { 0 };
int visited[25][25] = { 0 };
int move_x[4] = { 1,-1,0,0 };
int move_y[4] = { 0,0,-1,1 };
int dfs(int x, int y) {
	
	for (int i = 0; i < 4; i++) {
		int xx = move_x[i] + x;
		int yy = move_y[i] + y;
		if (xx >= n || xx < 0 || yy >= n || yy < 0) continue;
		
		if (!visited[xx][yy] && field[xx][yy]=='1') {
			visited[xx][yy]++;
			answers++;
			dfs(xx, yy);
		}
	}
	return answers;
}
int main() {

	cin >> n;
	int answer[313] = { 0 };
	int count = 0;
	// 필드 만들기
	for (int i = 0; i < n; i++) {
		cin >> field[i];
	}

	//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && field[i][j]=='1') {
				answers = 1;
				visited[i][j]++;
				int tmp = dfs(i, j);
					answer[count] = tmp;
					count++;
			}
		}
	}
	cout << count << '\n';

	sort(answer, answer + count);
	for (int i = 0; i < count; i++) {
		cout << answer[i] << '\n';
	}


	
}
