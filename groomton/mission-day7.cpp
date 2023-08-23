#include <iostream>
#include <vector>
using namespace std;

int x_arr[] = {1, -1, 0, 0, 1, 1, -1, -1};
int y_arr[] = {0, 0, 1, -1, -1, 1, -1, 1};
int n, k;
vector <int> v[1001];

int dfs(int i, int j) {
	int count = 0;
	
	for(int t = 0; t < 8; t++) {
		int xx = x_arr[t] + i;
		int yy = y_arr[t] + j;
		if(xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
		if(v[xx][yy] == -1) count++;
	}
	return count;
}

int main() {
	int answer = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0;j < n; j++) {
			int a;
			cin >> a;
			a = a ? -1 : 0;
			v[i].push_back(a);
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (v[i][j] == 0) {
				if(dfs(i, j) == k) answer++;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}
