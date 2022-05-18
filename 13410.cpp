#include <stdio.h>
#include <math.h>
int swap(int a[], int n) {
	int t;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 2; j <= n; j++) {
			if (a[i] < a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	return a[1];
}

int main() {
	int k, n;
	int an[1005] = { 0 };
	int c_su[10000] = { 0 };
	int a = 0;
	int b = 0;
	int aa = 0;
	int r = 0;
	int t = 0;
	int tt = 0;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		an[i] = n * i;
	}
	for (int i = 1; i <= k; i++) {
		tt = 0;
		t = 0;
		r = 0;
		while(an[i] / pow(10, tt) > 10) {
			tt++;//tt+1의값이 수의 자리수 
		}

		while (1) {
			
			t = pow(10,tt) * (an[i] % 10);
			an[i] = an[i] / 10;
			tt--;
			c_su[i] += t;
			if (tt < 0) break;
		}
	}
	aa = swap(c_su, k);
	printf("%d", aa);



}