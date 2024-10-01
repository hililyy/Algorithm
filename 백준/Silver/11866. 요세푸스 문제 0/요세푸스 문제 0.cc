#include <stdio.h>
int main() {
	int k, n, t; //n->사람수 / k->k번째 사람제거
	int j = 0;
	int a[1001] = { 0 };
	scanf("%d%d", &n, &k);
	t = k;
	int answer[1001] = { 0 };
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	for (int i = 0; i < n; i++) {
		a[t] = 0;
		answer[j] = t;
		if (j == n - 1) break;
		j++;
		for (int s = 0; s < k; s++) {
			t++;
			if (t > n) t = t - n;
			while (a[t] == 0) {
				t++; 
				if (t > n) { t = t - n; }
			}
			if (t > n) t = t - n;
		}

	}
	printf("<");
	for (int i = 0; i < n; i++) {
		printf("%d", answer[i]);
		if (i + 1 == n) break;
		printf(", ");
	}
	printf(">");
}