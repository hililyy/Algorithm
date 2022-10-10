#include <iostream>
using namespace std;
int sum_card(int n,int m,int card[]) {
	int max = 0;
	int sum = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = card[i] + card[j] + card[k];
				if (max < sum && sum <= m) { max = sum; }
			}
		}
	}
	return max;
}
int main() {

int card[1001] = { 0 };
int output=0;
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	cout<< sum_card(n, m, card);

}