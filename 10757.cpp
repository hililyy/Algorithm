#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char a[10005] = { 0 };
char b[10005] = { 0 };
char output[10005] = { 0 };

void swap(char a[], int x, int y) {
	int t = a[x];
	a[x] = a[y];
	a[y] = t;
}

void reverse(char a[]) {
	int tmp = 1;
	for (int i = 0; i < strlen(a)/2; i++) {
		swap(a, i, strlen(a) - tmp);
		tmp++;
	}
}


int main() {
	int a_len;
	int b_len;
	int count = 0;
	int tmp;
	char k;
	cin >> a >> b;

	a_len = strlen(a);
	b_len = strlen(b);
	reverse(a);
	reverse(b);
	

	if (a_len >= b_len) {
		for (int i = 0; i < (int)strlen(a); i++) {
			tmp = 0;
			if (i>= b_len ) {
				tmp = (a[i] - '0' );
			}
			else { tmp = (a[i] - '0') + (b[i] - '0'); }

			if (tmp >= 10) {
				if (i == a_len - 1) { 
					a[i + 1] = '1'; 
				}
				else { 
					a[i + 1]++; 
				}
				tmp -= 10;
				k = tmp + '0';
				output[count] = k;
				count++;
			}

			else if (tmp < 10) {
				k = tmp + '0';
				output[count] = k;
				count++;
			} 


		}
	}
	else if(a_len < b_len) {
		for (int i = 0; i < (int)strlen(b); i++) {
			tmp = 0;
			if (i >= a_len) {
				tmp = (b[i] - '0');
			}
			else { tmp = (a[i] - '0') + (b[i] - '0'); }

			if (tmp >= 10) {
				if (i == b_len - 1) {
					b[i + 1] = '1';
				}
				else {
					b[i + 1]++;
				}
				tmp -= 10;
				k = tmp + '0';
				output[count] = k;
				count++;
			}

			else if (tmp < 10) {
				k = tmp + '0';
				output[count] = k;
				count++;
			}

		}
	}
	reverse(output);

	for (int i = 0; i < (int)strlen(output); i++) {
		cout << output[i];
	}
}