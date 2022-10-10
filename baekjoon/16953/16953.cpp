#include <iostream>
#include <algorithm>
using namespace std;

long long a, b;
long long min_count = 1000000000;
bool flag = false;

void dfs(long long a, long long cnt) {
    if (a > b) return;
    
    else if (a == b) {
        flag = true;
        min_count = min(min_count,cnt);
    } 
    
    else if (a < b) {
        dfs(a * 2, cnt+1);
        dfs((a * 10) + 1, cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    
    dfs(a, 1);
    
    flag == false ? cout << "-1" : cout << min_count;
    return 0;
}
