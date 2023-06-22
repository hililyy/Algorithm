#include <iostream>

using namespace std;

int main() {
    int h, m, k;
    cin >> h >> m >> k;
    
    int hour = (m + k) / 60;
    int minute = (m + k) % 60;
    
    cout << (h + hour) % 24 << ' ' << minute;
}
