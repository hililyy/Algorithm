#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    cout.tie(0); cin.tie(0)->sync_with_stdio(0);
    int n;
    vector<pair<int, int>>v;
    cin >> n;
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), compare);
    
    for(int i=0;i<n;i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}

