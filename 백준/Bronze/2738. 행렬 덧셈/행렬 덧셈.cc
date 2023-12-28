#include <iostream>
using namespace std;
int n, m;
int s[101][101];

int main() {
  cout.tie(0); cin.tie(0) -> sync_with_stdio(0);

	cin >> n >> m;

	for(int i = 0; i < n; i++) {
	  for(int j = 0; j < m; j++) {
	    cin >> s[i][j];
	  }
	}
	
	for(int i = 0; i < n; i++) {
	  for(int j = 0; j < m; j++) {
	    int a;
	    cin >> a;
	    s[i][j] += a;
	  }
	}
	
	for(int i = 0; i < n; i++) {
	  for(int j = 0; j < m; j++) {
	    cout << s[i][j] << ' ';
	  }
	  cout << '\n';
	}
	
	return 0;
}