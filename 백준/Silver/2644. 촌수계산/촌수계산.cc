#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x, y, answer;
bool is_visited[101];
vector<int> v[101];

void dfs(int now, int end, int num) {
    is_visited[now] = true;
    if(now == end) { 
        answer = num; 
    }
    
    for(int t = 0; t < v[now].size(); t++) {
        int next = v[now][t];
        if(is_visited[next]) continue;
        dfs(next, end, num + 1);
    }
}

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> x >> y >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
	for (int i = 1; i <= n; i++) {
	    sort(v[i].begin(), v[i].end());
	}
    
    dfs(x, y, 0);
    
    if (answer == 0) {
        cout << "-1";
        return 0;
    }
    
    cout << answer;
    return 0;
}