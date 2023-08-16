#include <iostream>
using namespace std;
int main() {
	int n, a, b;
	char o;
	int answer = 0;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> a >> o >> b;
		
		switch (o) {
			case '+':
				answer += (a + b);
				break;

			case '-':
				answer += (a - b);
				break;

			case '*':
				answer += (a * b);
				break;

			case '/':
				answer += (a / b);
				break;

			default:
				break;
		}
	}
	
	cout << answer;
	return 0;
}
