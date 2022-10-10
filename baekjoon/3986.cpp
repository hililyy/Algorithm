#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int count = 0;
	
	for (int i = 0; i < n; i++) {
		stack<char> s;
		string input;
		cin >> input; //A or B 입력

		for(int j=0;j< input.length();j++){
			if(s.empty()) s.push(input[j]);
			else {
			    if (s.top() == input[j]) s.pop();
			    else s.push(input[j]);
			} 
			
			
		}
		if (s.empty()) count++;
	}
	cout << count;
}