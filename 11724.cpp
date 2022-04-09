#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[1001] = { 0 };
vector<int> connect[1001];

void dfs(int v) {
	visited[v] = true;
	sort(connect[v].begin(), connect[v].end());

	for (int node : connect[v]) {
		if (visited[node]) continue;
		dfs(node);
	}
}


int main() {
	int n, m, v;
	int count = 0;
	int start_num, end_num;
	cin >> n >> m ;

	for (int i = 0; i < m; i++) {
		cin >> start_num >> end_num;
		connect[start_num].push_back(end_num);
		connect[end_num].push_back(start_num);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			dfs(i);
			count++;
		}
	}
	cout << count;
	return 0;

}