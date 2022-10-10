#include <iostream>
using namespace std;
int main() {
	int n, k, copy_n;
	int temp = 0;
	int eat = 0;
	while (cin >> n >> k) {
		eat = 0;
		copy_n = n;
		temp = n / k;
		eat += temp;
		n = n % k + eat;
		while (n >= k) {
			if (n >= k) {
				temp = n / k;
				eat += temp;
				n = n % k + temp;
				if (n < k) break;
				else continue;
			}
		}
		cout << copy_n + eat << endl;;
	}
}