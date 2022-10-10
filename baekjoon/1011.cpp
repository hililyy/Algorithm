#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	int x, y, len, max;
	int count;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		len = y - x;
		max = sqrt(len);

		if (max * max == len) {
			count = max * 2 - 1;
		}
		else {
			if (max * max + max >= len) {
				count = max * 2;
			}
			else {
				count = max * 2 + 1;
			}
		}
		cout << count << endl;
	}


}