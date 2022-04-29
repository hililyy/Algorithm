#include <iostream>
#include <cstring>
using namespace std;
char test[999] = { 0 };
int final[999] = { 0 };
int main() {
	int n;
	int count = 0;
	int len = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		len = count = 0;
		cin >> test;
		len = strlen(test);
		if (test[0] == ')'||test[len-1]=='('||len%2==1) { final[i] = -1; continue; }
		for (int j = 0; j < len; j++) {
			if (test[j] == '(') count++;
			else if (test[j]==')') count--;
			if (count < 0) { final[i] = -1; break; }
		}
		if (count==0) final[i] = 1;
		else final[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		if (final[i] == -1) cout << "NO" << endl;
		else if (final[i] == 1) cout << "YES" << endl;
	}
}