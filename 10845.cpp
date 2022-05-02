#include <iostream>
#include <string>
using namespace std;

int first = -1;
int Queue[2000005] = { 0 };

int size() {
	return first + 1;
}

int empty() {
	if (first == -1) return 1;
	else return 0;
}

void push(int data) {
	Queue[++first] = data;
}

int pop() {
	int t;

	if (first == -1) return -1;

	else {
		t = Queue[0];

		for (int i = 0; i <= first; i++) {
			Queue[i] = Queue[i + 1];
		}
		
		first--;

		return t;
	}
}

int front() {
	if (first == -1) return -1;
	else return Queue[0];
}

int back() {
	if (first == -1)
		return -1;
	else return Queue[first];
}


int main() {
	int n;
	int data = 0;
	string command;

	cin >> n;	// 명령의 수	(1~2,000,000)

	for (int i = 0; i < n; i++) {

		cin >> command;

		if (!command.compare("push")) {
			cin >> data;
			push(data);
		}
		else if (!command.compare("pop")) cout << pop() << "\n";
		else if (!command.compare("size")) cout << size() << "\n";
		else if (!command.compare("empty")) cout << empty() << "\n";
		else if (!command.compare("front")) cout << front() << "\n";
		else if (!command.compare("back")) cout << back() << "\n";
	}

}