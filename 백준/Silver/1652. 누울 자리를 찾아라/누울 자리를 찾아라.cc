#include <iostream>
using namespace std;
    
int n, total_width, total_height;
char field[101][101];

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int width = 0;
        for(int j = 0; j < n; j++) {
            field[i][j] = s[j];
            if(field[i][j] == '.') width++;
            else {
                if(width >= 2) total_width++;
                width = 0;
            }
        }
        if(width >= 2) total_width++;
    }
    
    for(int j = 0; j < n; j++){
        int height = 0;
        for(int i = 0; i < n; i++) {
            if(field[i][j] == '.') height++;
            else {
                if(height >= 2) total_height++;
                height = 0;
            }
        }
        if(height >= 2) total_height++;
    }
    
    cout << total_width << ' ' << total_height;
    return 0;
}
