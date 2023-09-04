#include <bits/stdc++.h>
using namespace std;

int N, M, answer;
bool is_visited[2001], field[2001][2001];
vector <int> v[2001];

void dfs(int x) {
	for(int next: v[x]) {
		if(is_visited[next]) continue;
		is_visited[next] = true;
		dfs(next);
	}
}

int main() {
	cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
	
	cin >> N >> M;
	
	while(M--) {
		int x, y;
		cin >> x >> y;
		field[x][y] = true;
		if(field[y][x]) {
				v[x].push_back(y);
				v[y].push_back(x);
			}
	}
	
	for(int i = 1; i <= N; i++) {
		if(!is_visited[i]) {
			is_visited[i] = true;
			answer++;
			dfs(i);
		}
	}
	
	cout << answer;
	
	return 0;
}
