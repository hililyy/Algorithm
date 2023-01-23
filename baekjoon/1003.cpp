#include <iostream>
using namespace std;
int dp[41] = {0, 1};
int fibo(int n) {
    if (n == 0) return 0;
    else if (!dp[n]) {
        return dp[n] = fibo(n-1) + fibo(n-2);
    }
    return dp[n];
}

int main() {
    cout.tie(0); cin.tie(0)->sync_with_stdio(0);
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        fibo(n);
        if (n == 0) cout << "1 0\n";
        else if (n == 1) cout << "0 1\n";
        else {
            cout << dp[n-1] << ' ' << dp[n] << '\n';
        }
    }
}

