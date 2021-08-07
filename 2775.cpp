#include <iostream>
using namespace std;
int main() {
	int T;
	int k = 0;
	int n = 0;
	int input[9999] = { 0 };
	int person[20][20] = { 0 };

	for (int i = 0; i <= 14; i++) {	//층수
		for (int j = 1; j <= 15; j++) {	//호수
			if (i == 0) person[i][j] = j;
			if (j == 1) person[i][j] = 1;
			if(i>0&&j>0) person[i][j] = person[i - 1][j] + person[i][j - 1];
		}

	}
	cin >> T;
	for (int i = 0; i <T; i++) {
		cin >> k;	//층수
		cin >> n;	// 호수
		input[i] = person[k][n];
	}
	for (int i = 0; i < T; i++) {
		cout << input[i] << "\n";
	}
}