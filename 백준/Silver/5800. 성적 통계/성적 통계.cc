#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()  {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
  
  int t;
  int arr[51] = { 0 };
  cin >> t;
  for(int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    for(int j = 0; j < n; j++) cin >> arr[j];
    
    sort(arr, arr + n);
    
    int largest = 0;
    
    for(int k = 1; k < n; k++) {
      largest = max(largest, arr[k] - arr[k-1]);
    }
    
    cout << "Class "<< i <<'\n';
    cout << "Max "<< arr[n - 1] << ", Min " << arr[0] << ", Largest gap " << largest << '\n';
    
    memset(arr, 0, sizeof(int) * n);
  }
  
  return 0;
}