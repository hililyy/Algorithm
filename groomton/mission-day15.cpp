#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int N, K;
ll answer;
vector<pair<int, ll>> fruits;

int main() {
	cout.tie(0); cin.tie(0) -> sync_with_stdio(0);

	cin >> N >> K;
	
	for(int i = 1; i <= N; i++) {
		int P, C;
		cin >> P >> C;
		fruits.push_back({C / P, P});
	}
	
	sort(fruits.begin(), fruits.end());
	
	while(N--) {
		if(K >= fruits[N].second) {
			K = K - fruits[N].second;
			answer += fruits[N].first  * fruits[N].second;
		} else {
			answer += fruits[N].first * K;
			break;
		}
	}
	
	cout << answer;
	
	return 0;
}
