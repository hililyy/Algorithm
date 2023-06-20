#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
bool is_visited[100001];
int arr[100001];

void dfs(int k) {
    for(int i = 0; i < v[k].size(); i++) {
        int next = v[k][i];
        if(!is_visited[next]) {
            is_visited[next] = true;
            arr[next] = k;
            dfs(next);
        }
    }
}

int main() {
    cout.tie(0); cout.tie(0) -> sync_with_stdio(0);
    int n;
    
    cin >> n;
    
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
        v[a].push_back(b);
    }
    
    is_visited[1] = true;
    dfs(1);
    
    for(int i = 2; i <= n; i++) {
        cout << arr[i] << '\n';
    }
    
    return 0;
}
