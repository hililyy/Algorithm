#include <bits/stdc++.h>
using namespace std;

int N, M, K;
bool is_visited[2001], flag;
vector<int> v[2001];

pair<int, int> solution() {
	int answer = 0;
	
	while(!flag) {
		answer++;
		flag = true;
		int _min = N;
		
		for(int next: v[K]) {
			if(is_visited[next]) continue;
			_min = min(_min, next);
			flag = false;
		}
		
		if(flag) break;
		
		is_visited[_min] = true;
		K = _min;
	}
	
	return {answer, K};
}

int main() {
	cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
	
	cin >> N >> M >> K;
	
	while(M--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	is_visited[K] = true;
	
	auto answer = solution();
	
	cout << answer.first << ' ' << answer.second;
	
	return 0;
}
