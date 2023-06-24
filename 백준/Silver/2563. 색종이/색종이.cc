#include <iostream>
using namespace std;
 
int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    int n;
    int answer = 0;
    bool field[101][101] = { false };
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        for(int j = a; j < a + 10; j++) {
            for(int k = b; k < b + 10; k++) {
                if(field[j][k] == true) continue;
                field[j][k] = true;
                answer++;
            }
        }
    }
    
    cout << answer;
    
    return 0;
}
