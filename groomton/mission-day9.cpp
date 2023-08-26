#include <iostream>
#include <algorithm>
using namespace std;

int map[201][201];
bool double_exploede[201][201];

const int wx[] = {0, 0, -1, 1, 0};
const int wy[] = {1, -1, 0, 0, 0};

int n, k;
int answer;

int main() {
	cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
	
	cin >> n >> k;
	
	char input;
	
	for(int y = 1; y <= n; y++) {
		for(int x = 1; x <= n; x++) {
			cin >> input;
			if(input == '#') map[y][x] = -1;
			else if(input == '@') double_exploede[y][x] = true;
		}
	}
	
	int y, x;
	
	while(k--) {
		cin >> y >> x;
		for(int w = 0; w < 5; w++) {
			int ny = y + wy[w];
			int nx = x + wx[w];
			
			if(nx <= 0 || ny <= 0 || nx > n || ny > n || map[ny][nx] == -1) continue;
			
			if(double_exploede[ny][nx]) map[ny][nx] += 2;
			else map[ny][nx]++;
			
			answer = max(answer, map[ny][nx]);
		}
	}
	
	cout << answer;
	
	return 0;
}
