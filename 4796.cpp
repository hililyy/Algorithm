#include <iostream>
using namespace std;
int main() {
	int L, P, V;
	int output[1001] = { 0 };
	int count = 0;
	while (1) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) {
			break;
		}
		output[count] += L * (V / P);
		if (V % P > L) output[count] += L;
		else if (V % P <= L) output[count] += V % P;
		count++;
	} 

	for (int i = 0; i < count; i++) {
		cout << "Case " << i+1 << ": " << output[i] << endl;
	}
}