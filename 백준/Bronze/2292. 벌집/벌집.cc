#include <stdio.h>
int tsu(int n) {
	int i = 1;
	int j = 2;

	while (1) {
		if (n == 1) return 2;
		else if (((i*(i + 1)) / 2) < n && ((j*(j + 1)) / 2)>=n) { return i+2; break; }
		i++;
		j++;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) { printf("1"); return 0;}
	n = ((n - 2) / 6) + 1;
	printf("%d", tsu(n));



}