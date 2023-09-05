#include <bits/stdc++.h>
using namespace std;

int N, answer;
bool is_visited[1001][1001];
vector<int> field[1001];

int wx[] = {-1, 1, 0, 0};
int wy[] = {0, 0, -1, 1};

// dfs로 할 경우 시간초과 발생!
void dfs(int i, int j) {
	for(int t = 0; t < 4; t++) {
		int x = i + wx[t];
		int y = j + wy[t];
		
		if(x < 0 || y < 0 || x >= N || y >= N) continue;
		if(!is_visited[x][y] && field[x][y]) {
			is_visited[x][y] = true;
			dfs(x, y);
		}
	}
}

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({i, j});
	
	while(!q.empty()) {
		int first = q.front().first;
		int second = q.front().second;
		q.pop();
		
		for(int t = 0; t < 4; t++) {
			int x = first + wx[t];
			int y = second + wy[t];
			
			if(x < 0 || y < 0 || x >= N || y >= N) continue;
			if(!is_visited[x][y] && field[x][y]) {
				is_visited[x][y] = true;
				q.push({x, y});
			}
		}
	}
}

int main() {
	cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
	
	cin >> N;
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < N; j++) {
			int a;
			cin >> a;
			field[i].push_back(a);
		}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!is_visited[i][j] && field[i][j]) {
				is_visited[i][j] = true;
				answer++;
				bfs(i, j);
			}
		}
	}
	
	cout << answer;
	
	return 0;
}
