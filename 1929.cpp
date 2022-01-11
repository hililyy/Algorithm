#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n, m;
	int count = 0;
	bool prime[1000001];

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 2; i <= 1000000; i++) {
		prime[i] = true;
	}
	prime[1] = false;

	for (int i = 2; i <= sqrt(1000000); i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= 1000000; j = j + i) {
				prime[j] = false;
			}
		}

	}

	for (int i = n; i <= m; i++) {
		if (prime[i]) cout << i << '\n';
	}

}