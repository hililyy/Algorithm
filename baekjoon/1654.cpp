#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    vector <long long> lan;
    int k, n;
    long long start, end, mid;
    cin >> k >> n;
    
    for(int i = 0; i < k; i++) {
        int a;
        cin >> a;
        lan.push_back(a);
    }
    
    start = 1;
    end = *max_element(lan.begin(), lan.end());
    
    while(start <= end) {
        int count = 0;
        mid = (start + end) / 2;
        for(int i = 0; i < k; i++) {
            count += lan[i] / mid;
        }
        if (count < n) end = mid - 1;
        else start = mid + 1;
    }
    cout << end;
    
    return 0;
}
