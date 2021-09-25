#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[2][1001] = { 0 };
vector<int> connect[1001];
queue<int> q;

void dfs(int v) {
	visited[0][v] = true;
	sort(connect[v].begin(), connect[v].end());
	cout << v << ' ';

	/*for (int i = 0; i < connect[v].size(); i++) {
		if (visited[connect[v][i]]) {
			continue;
		}
		else {
			dfs(connect[v][i]);
		}
	}*/

	for (int node : connect[v]) {
		if (visited[0][node]) continue;
		dfs(node);
	}
}

void bfs(int v) {

	q.push(v);
	v = q.front();
	visited[1][v] = true;

	while(!q.empty()) {

		v = q.front();
		cout << v << ' ';
		q.pop();

		sort(connect[v].begin(), connect[v].end());

		for (int node : connect[v]) {
			if (!visited[1][node]) {
				q.push(node);
				visited[1][node] = true;
			}
		}
	}

}
int main() {
	int n, m, v;
	

	int start_num, end_num;
	cin >> n >> m >> v;


	for (int i = 0; i < m; i++) {
		cin >> start_num >> end_num;
		connect[start_num].push_back(end_num);
		connect[end_num].push_back(start_num);
	}
	
	dfs(v);
	cout << "\n";
	bfs(v);
	return 0;

}