#include <iostream>
using namespace std;

int main() {
    cout.tie(0); cin.tie(0)->sync_with_stdio(0);
    int t, n;
    int dp[41] = {0, 1, 1};
    for(int i = 3; i <= 40; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    } 
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        if(n==0) cout << "1 0\n";
        else if(n==1) cout << "0 1\n";
        else {
            cout << dp[n-1] << ' ' << dp[n] << '\n';
        }
    }
}

