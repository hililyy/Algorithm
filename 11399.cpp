#include <iostream>
using namespace std;
void Array(int n, int p[]) {
	int t;
	for (int i = 1; i <= n-1; i++) {
		for (int j = i+1; j <= n; j++) {
			if (p[i] > p[j]) {
				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
}
int cal(int n,int p[]) {
	int m = 0;
	int nn;
	nn = n;
	for (int i = 1; i <= nn; i++) {
		m += p[i] * n;
		n--;
	}
	return m;
}

int main() {
	int n;
	int p[1001] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	Array(n, p);
	cout << cal(n, p); 
}