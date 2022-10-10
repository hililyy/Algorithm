#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
1. vector 만들기( 만들고 선언), visit배열 만들기
2. make_edge만들기
3. dfs만들기

*/
int visit[10001] = { 0 };
int count_num = -1;

void make_edge(vector <int> vec[],int a,int b) {
	vec[a].push_back(b);
	vec[b].push_back(a);
}

void dfs(int v, vector <int> vec[]) {
	if (visit[v]) return;
	else {
		visit[v] = true;
		count_num++;
		for (int i = 0; i < vec[v].size(); i++) {
			int x = vec[v][i];
			dfs(x, vec);
		}
	}
}

int main() {
	int computer_num=0;	// 컴퓨터의 수
	int connect_num=0;	// 연결된 컴퓨터의 수
	int a, b;
	cin >> computer_num >> connect_num;
	vector <int>* vec = new vector <int>[computer_num + 1 ];

	for (int i = 0; i < connect_num; i++) {
		cin >> a >> b;
		make_edge(vec, a, b);
	}
	dfs(1, vec);
	cout << count_num;
}