#include <iostream>
using namespace std;

int main() {
    
    cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    
    long long s;
    long long sum = 0;
    long long count = 1;
    cin >> s;
    
    while(true){
        sum = count * (count + 1) / 2;

        if (sum <= s) count ++;
        else break;
    }
     cout << count-1;
}
