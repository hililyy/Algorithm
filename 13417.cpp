// 받은 값의  n과 n-1의 크기를 비교한다.

// ​

// * n-1, n 크기 비교 - 1) n-1 < n : n을 가장 오른쪽에 배치

//                 - 2) n-1 >= n       -1) 가장 왼쪽수 >= n : n을 가장 왼쪽에 배치

//                                     -2) 가장 왼쪽 수 < n : n을 가장 오른쪽에 배치
#include <iostream>
using namespace std;
int main() {
	int n;
	char data[1005] = { 0 };
	int count[1005] = { 0 };
	char output[1005][1005] = { 0 };
	int len;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> len;
		for (int j = 0; j < len; j++) {
			cin >> data[j];
			if (j == 0) { 
				output[i][count[i]] = data[j];
				count[i]++; 
			}


			if (j > 0 && data[j - 1] < data[j]) {
				output[i][count[i]] = data[j];
				count[i]++;
			}

			else if (j > 0 && data[j - 1] >= data[j]) {
				if (output[i][0] >= data[j]) {
					for (int k = count[i]; k > 0; k--) {
						output[i][k] = output[i][k-1];
					}
					output[i][0] = data[j];
					count[i]++;
				}
				else {
					output[i][count[i]] = data[j];
					count[i]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < count[i]; j++) {
			cout << output[i][j];
	}
		cout << "\n";
	}
}
