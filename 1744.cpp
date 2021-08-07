// memo

// 1. 오름차순으로 정렬후 큰 수끼리 묶는다 (큰 틀에서 보면)

// 2. 1) '-'(음수)가 짝수개이면 절대값이 큰 수 순서로 2개씩 묶어 계산( - * - = +의 원리)

//      2) '-'(음수)가 홀수개이면 절대값이 큰 수 순서로 2개씩 묶어 계산한다. 이때 홀수개이므로 절대값이 가장 작은 음수 하나가 남는다. 이에 대해 ..

// 3. (2번의 나머지 하나의 음수에 대해)

//       1) 숫자 0 존재 -> 0과 묶어 계산

//       2) 숫자 0 미존재시 -> 음수 그대로 더한다.

// 4. 숫자 1존재시 다른 수와 묶지 않고 단독으로 더한다.

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;  // 숫자를 몇개 입력받을지?
	int arr[100] = { 0 };  // 입력받은 변수 저장 배열
	int minus_num = 0;  // 음수의 개수
	int plus_num = 0;  // 0과 1을 제외한 양수의 개수
	int count1 = 0;   // 1의 개수
	int count0 = 0;   // 0의 개수
	int output = 0;   // 출력 결과 값 (계산 후 이곳에 누적 계산)

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < 0) minus_num++;
		else if (arr[i] > 1) plus_num++;
		else if (arr[i] == 1) count1++;
		else if (arr[i] == 0) count0++;
	}

	sort(arr, arr + n);

	int j = 0;

	for (int i = 0; i < minus_num/2; i++) {
		output += arr[j] * arr[j + 1];
		j += 2;
	}

	if (minus_num % 2 == 1 && count0 == 0) {
		output += arr[minus_num - 1];
	}

	if (count1 > 0) output += count1;

	j = minus_num + count0 + count1;

	if (plus_num % 2 == 0) {

		for (int i = 0; i < plus_num / 2; i++) {
			output += arr[j] * arr[j + 1];
			j += 2;
		}
	}
	else {
		output += arr[j];
		j++;
		for (int i = 0; i < plus_num / 2; i++) {
			output += arr[j] * arr[j + 1];
			j += 2;
		}
	}

	cout << output;
}