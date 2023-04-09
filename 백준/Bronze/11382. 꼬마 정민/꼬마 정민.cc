#include <iostream>
using namespace std;
int main() {
    long long n;
    long long sum = 0;
    for(int i = 0; i < 3; i++) {
        cin >> n;
        sum += n;
    }
    cout << sum;
}