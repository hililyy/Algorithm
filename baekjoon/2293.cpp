#include <iostream>
using namespace std;
int dp[10000];
int coin[10001];

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    
    dp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        if (coin[i] > k) continue;
        for(int j = coin[i]; j <= k; j++){
            dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[k];
    return 0;
}
