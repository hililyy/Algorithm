#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[100010] = {0};
vector <int> vec[100010];
int output[200010] = {0};

int cnt = 1;

void dfs(int v) {
    visited[v] = true;
    output[v] = cnt++;
    for (int node: vec[v]) {
        if (visited[node]) continue;
        dfs(node);
    }
}

int main() {
    
    cin.tie(0) -> sync_with_stdio(0);
    cout.tie(0) -> sync_with_stdio(0);
    int n, m, r;

    cin >> n >> m >> r;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    for (int i = 0; i < n; i++) {
        sort(vec[i].begin(), vec[i].end());
    }
    //TODO : 우선순위 큐 사용
    
    dfs(r);
    
    for (int i = 1; i <= n; i++) {
        cout << output[i] <<'\n';
    }
}
