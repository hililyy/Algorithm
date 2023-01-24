#include <iostream>
#include <algorithm>
using namespace std;
int tree[1000001];

int main() { 
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    int n, m, result = 0;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) cin >> tree[i];
    
    int start = 0;
    int end = *max_element(tree, tree+n);
    
    while(start <= end) {
        int middle = (start + end) / 2;
        long long int cut_total = 0; // 10억 -> long long int
        
        for(int i = 0; i < n; i++) {
            if(tree[i] > middle) {
                cut_total += (tree[i] - middle);
            }
        }
        if(cut_total < m) end = middle - 1;
        else {
            result = middle;
            start = middle + 1;
        }
    }
    cout << result;
    return 0;
}
