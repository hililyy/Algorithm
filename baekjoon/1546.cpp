#include <iostream>
using namespace std;
int main() {
	int n,score;
	int max = 0;
	double total = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score;
		if (max < score) max = score;
		total += score * 100;
	}
	total = (total/(double)max)/(double)n;
	printf("%lf", total);
}