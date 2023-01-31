#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    vector<pair<int, int>> v;
    int t, n, max;
    int count = 1;
    cin >> t;
    for(int test = 0; test < t; test++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            v.push_back(pair<int, int>(a, b));
        }
        sort(v.begin(), v.end());
        max = v[0].second;
        
        for(int i = 1; i < n; i++) {
            if(max > v[i].second) {
                max = v[i].second;
                count++;
            }
        }
        cout << count << '\n';
        count = 1;
        v.clear();
    }
    return 0;
}
