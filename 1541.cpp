// memo

// 0. 그리디 알고리즘

// 1. 작은수 - 홀수

// 2. '-'가 오면 괄호 시작

// 3. '-' 후 '-' 시 괄호 x

// 4. -'가 나오면 그 뒷수는 모두 '-'가 나오기 전 수들의 합에서 뺀다.

// 5. 반드시 앞에서 뒤를 빼는 상황만 있을까?

//       입력 : '-'가 나오면 또 '-'가 나올때까지 괄호 -> 모든숫자 누적 합

//                   두번 째 '-' 바로 뒷 수는 뺄 변수에 누적

// 6. 크게 앞수, 뒷수로 분리(변수 2개 이용)

// 7. 문자, 숫자를 어떻게 구분할 것인가? (가장오래걸림)

//    -> 숫자는 숫자끼리 su라는 변수에 차례대로 저장, 문자는 문자끼리 mark라는 변수에 차례대로 저장했다.


#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;
int main() {
	char input[100] = { 0 }; //수는 0~99999
	int imsi[10] = { 0 };
	int su[100] = { 0 };
	char mark[100] = { 0 };
	int len = 0;

	cin >> input;
	len = strlen(input);

	int p, k, count,z,q;
	p = k = z  = 0;
	count = -1;

	for (int i = 0; i < len; i++) {
		if (isdigit(input[i])) {
			imsi[p] = input[i]-48;
			count++;
			p++;
		}
		else if(isdigit(input[i])==0) {
			mark[k] = input[i];
			k++;
			q = count;
			for (int j = 0; j <= count; j++) {
				su[z] += imsi[j] * pow(10, q);
				q--;
			}
			count = -1;
			z++;
			while(p--) imsi[p] = 0;
			p = 0;
		}
		if (i == len - 1) {
			q = count;
			for (int j = 0; j <= count; j++) {
				su[z] += imsi[j] * pow(10, q);
				q--;
			}
			z++;
		}
	}

	int flag = 0;
	int L_num = su[0];
	int S_num = 0;

	for (int i = 0; i < k; i++) {
		if (mark[i] == '+' && flag == 0) { L_num += su[i + 1]; }
		else if (mark[i] == '-' && flag == 0) {	
			flag = 1;	
			S_num += su[i + 1];
		}
		else if (mark[i] == '+' && flag == 1) {
			S_num += su[i + 1];
		}
		else if (mark[i] == '-' && flag == 1) {
			S_num += su[i + 1];
		}
	}
	cout << L_num - S_num;		
}