#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int>stack;
	int k, n;
	int sum = 0;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		if (n != 0) {
			stack.push(n);
		}
		else { stack.pop(); }
	}
	for (int i = stack.size(); i > 0; i--) {
		sum += stack.top();
		stack.pop();
	}
	printf("%d", sum);
}