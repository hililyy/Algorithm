#include <iostream>
using namespace std;
int main() {
	int n;
	int score[101] = { 0 };
	int count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	for (int i = n - 1; i > 0; i--) {
		if (score[i] <= score[i - 1]) {
			count += score[i-1] - score[i] + 1;
			score[i - 1] = score[i] - 1;
		}
	}

	cout << count;

}