#include <iostream>

using namespace std;
void swap(int a[], int x, int y) {
	int t = a[x];
	a[x] = a[y];
	a[y] = t;
}

void reverse(int a[], int size) {
	int tmp = 1;
	for (int i = 0; i < (size+1) / 2; i++) {
		swap(a, i, size+1 - tmp);
		tmp++;
	}
}
int a[10001] = { 0 };
int search(int input,int flag) {
	int count = 1;
	int size = 0;
	int output = 0;

	a[0] = 1;

	while (1) {
	for (int i = 0; i <= size; i++) {
		if (count == input) {
			output = a[i];
			flag = 2;
			break;
		}
		else {
			count++;
		}
	}
	if (flag == 0) {
		flag = 1;
		size++;
		a[size] = a[size - 1] + 1;
		reverse(a, size);
	}

	else if (flag == 1) {
		flag = 0;
		reverse(a, size);
		size++;
		a[size] = a[size - 1] + 1;
	}
	else if (flag == 2) {
		return output;
		break;
	}
	}

}
int main() {

	int input;
	int output1, output2;
	cin >> input;
	int flag = 1;	//0이면 오름차순 1이면 내림차순
	output1 = search(input, flag);
	flag = 0;
	output2 = search(input, flag);
	
	cout << output1<<'/'<<output2;

	
}