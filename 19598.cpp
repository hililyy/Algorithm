#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    int n;
    long long start;
    priority_queue<int, vector<int>, greater<int>> q;
    vector<pair<long long, long long>> v;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        v.push_back(pair<long long, long long>(a,b));
    }
    
    sort(v.begin(), v.end());
    
    q.push(v[0].second);
    
    for(int i = 1; i < n; i++) {
        q.push(v[i].second);
        if(q.top() <= v[i].first) q.pop();
    }
    cout << q.size();
    return 0;
}
