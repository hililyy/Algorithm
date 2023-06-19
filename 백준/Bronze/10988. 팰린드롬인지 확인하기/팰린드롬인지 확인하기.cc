#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;
    
    string frontStr = str.substr(0, str.length() / 2);
    string endStr = str.substr(str.length() - str.length() / 2);
    
    reverse(frontStr.begin(), frontStr.end());
    
    if (frontStr == endStr) {
        cout << "1";
    } else {
        cout << "0";
    }
    
    return 0;
}