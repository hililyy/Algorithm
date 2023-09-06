#include <bits/stdc++.h>
using namespace std;

int N, M, K, answer;
bool is_visited[2001], flag;
vector<int> v[2001];

int main() {
	cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
	
	cin >> N >> M >> K;
	
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	is_visited[K] = true;
	
	while(!flag) {
		answer++;
		flag = true;
		int minium = N;
		
		for(int next: v[K]) {
			if(is_visited[next]) continue;
			flag = false;
			minium = min(minium, next);
		}
		
		if(flag) break;
		
		is_visited[minium] = true;
		K = minium;
	}
	
	cout << answer << ' ' << K;
	
	return 0;
}
