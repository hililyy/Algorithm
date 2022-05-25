#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[100001] = {0};
int output [100001] = {0};
int cnt = 1;
vector <int> vec[100001];
queue <int> q;


void bfs (int v) {
    q.push(v);
    visited[v] = true;
    
    while (!q.empty()) {
        v = q.front();
        output[v] = cnt++;
        q.pop();
        
        for (int node: vec[v]) {
            if (!visited[node]) {
                q.push(node);
                visited[node] = true;
            }
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0); cout.tie(0);
    
    int n, m, r;
    cin >> n >> m >> r;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) sort(vec[i].begin(), vec[i].end());
    
    bfs(r);
    
    for (int i = 1; i <= n; i++) cout << output[i] << '\n';
} 
