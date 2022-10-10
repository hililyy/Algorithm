#include <iostream>
using namespace std;
int main() {
    int N; // 기타줄
    int M; // 브랜드 수
    int minCost_1 = 1001, minCost_6 = 1001;
    int cost_1, cost_6;
    int num = 0, output = 0;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> cost_6 >> cost_1;
        
        if(cost_1 < minCost_1) minCost_1 = cost_1;
        if(cost_6 < minCost_6) minCost_6 = cost_6;
    }
    
    num = minCost_6 / minCost_1; 
    
    if(minCost_1==0 || minCost_6 ==0) {     // 기타 줄이 공짜면 
        output = 0;
    } else if(minCost_6<minCost_1) {  // 세트가 낱개보다 쌀 경우
        output = (N/6) * minCost_6;
        if((N%6)>0) output +=minCost_6;
        
    } else if(minCost_6 < minCost_1 * 6){  // 세트가 낱개 6개보다 쌀경우
        output = (N/6) * minCost_6; 
        N = N % 6; 
        if(N >= num) output += minCost_6;   // 몇개까지 낱개로 사야하는지
        else output += N * minCost_1;
    } else output = N*minCost_1;    // 낱개로 모두 살경우
    
    cout<< output;
}
