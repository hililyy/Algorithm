#include <iostream>
using namespace std;
 
int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    int answer = 0;
    bool field[101][101] = { false };
    
    for(int i = 0; i < 4; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        for(int j = a; j < c; j++) {
            for(int k = b; k < d; k++) {
                if(field[j][k] == true) continue;
                field[j][k] = true;
                answer++;
            }
        }
    }
    
    cout << answer;
    
    return 0;
}
