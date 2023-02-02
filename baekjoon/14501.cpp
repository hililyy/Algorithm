#include <iostream>
#include <math.h>
using namespace std;
int main() {
    cout.tie(0); cin.tie(0)->sync_with_stdio(0);
    int n;
    int t[1001] = {0};
    int p[1001] = {0};
    int dp[1001] = {0};
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for(int i = n; i > 0; i--) {
        if(t[i] > n - i + 1) dp[i] = dp[i+1];
        else {
            dp[i] = max(dp[i+1],p[i]+dp[i+t[i]]);
        }
    }
    cout << dp[1];
}
