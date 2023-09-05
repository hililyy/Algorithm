#include <bits/stdc++.h>
using namespace std;

int N, K, maxium_home, maxium_cnt;
bool is_visited[1001][1001];
int home_cnt[1001];
vector<int> field[1001];

int wx[] = {-1, 1, 0, 0};
int wy[] = {0, 0, -1, 1};

bool bfs(int i, int j, int type) {
	queue <pair<int, int>> q;
	q.push({i, j});
	int cnt = 1;
	
	while(!q.empty()) {
		int first = q.front().first;
		int second = q.front().second;
		q.pop();
		
		for(int t = 0; t < 4; t++) {
			int x = first + wx[t];
			int y = second + wy[t];
			
			if(x < 0 || y < 0 || x >= N || y >= N) continue;
			if(!is_visited[x][y] && type == field[x][y]) {
				is_visited[x][y] = true;
				cnt++;
				q.push({x, y});
			}
		}
	}
	
	return cnt >= K ? true : false;
}

int main() {
	cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
	
	cin >> N >> K;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			int a;
			cin >> a;
			field[i].push_back(a);
		}
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!is_visited[i][j]) {
				is_visited[i][j] = true;
				
				int type = field[i][j];
				
				if(bfs(i, j, type)) {
					home_cnt[type]++;
					
					if(maxium_cnt < home_cnt[type]) {
						maxium_cnt = home_cnt[type];
						maxium_home = type;
					} 
					else if(maxium_cnt == home_cnt[type]) maxium_home = max(type, maxium_home);
				}
			}
		}
	}
	
	cout << maxium_home;
	
	return 0;
}
