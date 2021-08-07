#include <iostream>
using namespace std;
int main() {
	int a, b, v;	// a:올라기는 미터, b:내려가는 미터, v: 총길이

	cin >> a >> b >> v;

	if ((v - b) % (a - b) > 0) {
		cout << (v - b) / (a - b) + 1;
	}
	else {
		cout << (v - b) / (a - b);
	}

}