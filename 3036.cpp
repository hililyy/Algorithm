#include <iostream>
using namespace std;
int main() {
	int n;
	int ring[1011] = { 0 };
	int A[1011] = { 0 }; //나머지
	int B[1011] = { 0 };	//몫
	int count=0;
	int count1 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ring[i];
		if (count1 < ring[i]) count1 = ring[i];
	}

	for (int i = 1; i < n; i++) {
		count = count1;
		while (1) {
			if (ring[0] % count == 0 && ring[i] % count == 0) {
				A[i] = ring[0] / count;
				B[i] = ring[i] / count;
				cout << A[i] << "/" << B[i] << endl;
				break;
			}
			else count--;

		}
	}
}