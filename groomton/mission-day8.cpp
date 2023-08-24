#include <iostream>
using namespace std;
int main() {
	int n;
	int arr[3] = {14, 7, 1};
	int count = 0;
	
	cin >> n;
	
	for(int i = 0; i < 3; i++) {
		count += n / arr[i];
		n = n % arr[i];
	}
	
	cout << count;
	return 0;
}
