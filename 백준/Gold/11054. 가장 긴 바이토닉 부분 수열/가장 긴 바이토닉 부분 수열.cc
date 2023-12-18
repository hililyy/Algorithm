#include <iostream>
using namespace std;

int n, answer;
int sequence[1001], dp[1001], r_dp[1001];

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> sequence[i];

    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
        for(int j = i - 1; j >= 1; j--) {
            if(sequence[i] > sequence[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // cout << dp[i] << ' ';
    }
    // cout << endl;
    for(int i = n; i >= 1; i--) {
        r_dp[i] = 1;
        for(int j= n; j > i; j--) {
          // cout << "i: " << i << " j: " << j ;
          // cout << " a: " << sequence[i] << " b: " << sequence[j] << endl;
            if(sequence[i] > sequence[j]) {
                r_dp[i] = max(r_dp[i], r_dp[j] + 1);
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
      // cout << r_dp[i] << ' ';
      answer = max(answer, dp[i] + r_dp[i]);
    }
    // cout << endl;
    cout << answer - 1;

    return 0;
}