#include <iostream>
using namespace std;

int main() {
    int a, b;
    int count = 2;
    int sum[10001] = {0};
    
    cin >> a >> b;
    sum[1] = 1;

    for(int i = 1; i <= b;) {
        int j = 0;
        while(j < count) {
            j++;
            i++;
            sum[i] = sum[i-1] + count;
        }
        count ++;
    }
    cout << sum[b] - sum[a-1];
}
