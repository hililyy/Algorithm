#include <iostream>
using namespace std;
int main()
{
	int N, K;	//N가지 종류의 동전, 동전의 합 K
	int coin[10] = { 0 };
	int count = 0;
	int t;

	cin >> N >> K;

	for (int i = 0; i < N; i++){
		cin >> coin[i];		}

	for (int i = N-1; i >= 0; i--) {
		if (K >= coin[i]) { 
			t= (K / coin[i]);
			count += t;
			K = K - coin[i] * t;
		}
	}
	cout << count;


}