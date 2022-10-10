#include <iostream>
#include <algorithm>
using namespace std;
bool com(int a, int b) {
	return a > b;
}

int main() {
	int n;
	int a[51] = { 0 };
	int b[51] = { 0 };
	int output = 0;

	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	sort(a, a + n);
	sort(b, b + n, com);

	for (int i = 0; i < n; i++) {
		output += a[i] * b[i];
	}
	cout << output;
}