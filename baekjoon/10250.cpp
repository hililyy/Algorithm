#include <iostream>
using namespace std;
int main() {
	int  T, H, W, N;     // T: 입력개수, H: 높이, W: 너비, N: 몇번째 방
	int output;
	int Q, R;  //   Q = N/H, R = N%H

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		Q = N / H;
		R = N % H;
		if (R != 0) Q++;
		else if (R == 0) R = H;
		output = (R * 100) + Q;

		cout << output << "\n";
	}
}