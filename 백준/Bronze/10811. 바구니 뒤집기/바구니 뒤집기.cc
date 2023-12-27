#include <iostream>
using namespace std;
int n, m, a, b;
int s[101] = { 0 };

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);

	cin >> n >> m;

	for(int i = 1; i <= n; i++) s[i] = i;

	while(m--) {
		cin >> a >> b;

		for(int i = 0; i <= (b - a) / 2; i++) swap(s[a + i], s[b - i]);
	}

	for(int i = 1; i <= n; i++) cout << s[i] << ' ';
	
	return 0;
}