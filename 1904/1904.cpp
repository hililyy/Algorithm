#include <iostream>
using namespace std;
long long number[1000001]= {0,1,2,3};

void dp(int n) {
    if (n < 4) {
        number[n] = n;
        return;
    } else {
        for (int i = 4; i <= n; i++) {
            number[i] = (number[i-1] + number[i-2]) % 15746;
        }
    }
}

int main() {
    int n;
    cin >> n;
    dp(n);
    cout << number[n];
}
