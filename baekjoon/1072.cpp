#include <iostream>
using namespace std;

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    long long x, y;
    int score, start = 0, end = 1000000000, mid;
    
    cin >> x >> y;
    score = y * 100 / x;

    if(score >= 99) { cout << "-1"; return 0; }
    
    while(start <= end) {
        mid = (start + end) / 2;
        int score_new = (y + mid) * 100 / (x + mid); 
        if(score < score_new) end = mid - 1;
        else start = mid + 1;
    }
    cout << start;
    
    return 0;
}

/*
1. 백분율 계산 시 *100을 먼저 하면 소수점을 버린 정수로 계산 가능 (이 순서로 안하면 제대로된 계산이 안됨.)
2. 승률을 올릴 수 없는 경우 -> 현재승률이 99% or 100%일 경우 (99%는 100%가 되어야 조건에 만족하는데 문제 구조상모든 판을 이길 수 없음. 100%일 경우 101%는 존재하지 않음.)
3. end값 설정 -> 문제에서 10억판을 더 할수 있다고 했기 때문에 10억을 end로 지정 (이때 int가 아닌 long long으로 값 저장)
4. 최소 몇판을 이겨야하는지 물은 것이므로 start값을 print함.
*/
