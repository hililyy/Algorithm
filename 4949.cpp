#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int des(char a[]) {
	stack<char>stack;
	int len = strlen(a);

	for (int i = 0; i < len; i++) {
		if (stack.empty() && (a[i] == ')' || a[i] == ']')) return 0;
		if (a[i] == '(') stack.push('a');
		else if (a[i] == '[') stack.push('b');
		else if (a[i] == ')' && stack.top() == 'a') stack.pop();
		else if (a[i] == ']' && stack.top() == 'b') stack.pop();
		else if (a[i] == ')' && stack.top() != 'a') return 0;
		else if (a[i] == ']' && stack.top() != 'b') return 0;
		
	}
		if (stack.empty()) return 1;
		else if (!(stack.empty())) return 0;

}
int main() {
	char a[150] = { 0 };
	int t;
	while (1) {
		cin.getline(a, 150);
		if (a[0] == '.' && a[1] == '\0') {
			break;
		}
		t = des(a);
		if (t == 1) printf("yes\n");
		else if (t == 0)printf("no\n");
	}
	return 0;


}