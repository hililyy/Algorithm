#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[10001];
bool is_visited[10001];
int counter[10001];
int cnt, maximum;

void dfs(int num, int start) {
    is_visited[num] = true;
    for(int i=0;i<v[num].size();i++) {
        int next = v[num][i];
        if(!is_visited[next]) {
            cnt ++;
            is_visited[next] = true;
            dfs(next, start);
        }
    }
    counter[start] = max(counter[start], cnt);
}

int main() {
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    for(int i=1; i<=n;i++) {
        memset(is_visited, false, n + 1);
        cnt = 0;
        dfs(i, i);
        maximum = max(maximum, counter[i]);
    }
    
    for(int i=1;i<=n;i++) {
        if(counter[i] == maximum) {
            cout << i << ' ';
        }
    }
    return 0;
}
