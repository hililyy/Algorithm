#include <iostream>
using namespace std;
int test(int n){
	int count = 0;
	int m;
	int k;
	if (n == 4 || n == 7) return -1;
	if (n == 3) return 1;
	m = n / 5;
	n = n - (m * 5);
	if (n == 0) return m;
	count += m;

	while (1) {
		if (n % 3 == 0) {
			count += n / 3;
			return count;
		}
		else if (n % 3 != 0) {
			count--;
			n += 5;
		}
	}


}
int main() {
	int n;
	cin >> n;
	cout << test(n);


}