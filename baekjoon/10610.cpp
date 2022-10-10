// memo

// 1. 0은 반드시 존재

// 2. 출력 시 0은 반드시 가장 끝에 존재

// 3. 각 자리의 수의 합은 3으로 나누어 떨어짐

// 4. 위 조건을 만족하면 내림차 순으로 정렬 후 출력

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[100005] = { 0 };

int main() {
	string n = { 0 };
	int len = 0;	// n의 길이
	cin >> n;
	len = n.size();
	int flag = 0;
	int sum = 0;

	for (int i = 0; i < len; i++) {
		if (n[i] == '0') flag = 1;
		sum += (n[i]-'0');
		arr[i] = n[i] - '0';
	}
	if (flag == 0 || sum % 3 != 0) { cout << "-1" << endl; }
	else {
		sort(arr, arr + len);
		for (int i = len - 1; i >= 0; i--) {
			cout << arr[i];
		}
	}
}