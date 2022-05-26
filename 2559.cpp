#include <iostream>
using namespace std;

int main() {
    int n, k;
    int arr[100001] = {0};
    int sum = 0;
    
    cin >> n >> k;
    
    int first_num;
    int end_num;
    int max = -101;
    
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (i <= k) sum += arr[i];
    }

    max = sum;
    
    for(int i = 1; i < n-k+1; i++) {
        first_num = arr[i];
        end_num = arr[i+k];
        sum -= (first_num - end_num);
        if (max < sum) max = sum;
    }
    cout << max;
}