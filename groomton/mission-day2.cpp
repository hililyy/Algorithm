#include <iostream>
using namespace std;
int main() {
	int n, h, m;
	cin >> n >> h >> m;
	int sum = 0;
	
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum += a;
	}
	
	sum = sum % 1440;
	
	if (60 - m > (sum % 60)) {
		cout << (h + (sum / 60)) % 24 << ' ' << (m + (sum % 60)) % 60;
	} else {
		cout << ((h + (sum / 60)) + 1) % 24 << ' ' << (m + (sum % 60)) % 60;
	}
	
	return 0;
}
