#include <iostream>
using namespace std;
int main() {
	bool flag = false;
	int n, before, after;
	
	cin >> n >> before;
	int sum = before;
	for(int i = 1; i < n; i++) {
		cin >> after;
		if (!flag) {
			if (before > after) { flag = true; }
			before = after;
		} else {
			if (before < after ) { cout << '0'; return 0; }
			before = after; 
		}
		sum += before;
	}
	
	cout << sum;
	return 0;
}
