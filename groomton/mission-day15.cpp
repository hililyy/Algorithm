#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int N, K;
vector<pair<int, ll>> fruits;

ll solution() {
	ll answer = 0;
	
	while(N--) {
		if(K >= fruits[N].second) {
			K -= fruits[N].second;
			answer += fruits[N].first  * fruits[N].second;
		} else {
			answer += fruits[N].first * K;
			break;
		}
	}
	return answer;
}

int main() {
	cout.tie(0); cin.tie(0) -> sync_with_stdio(0);

	cin >> N >> K;
	
	for(int i = 0; i < N; i++) {
		int P, C;
		cin >> P >> C;
		fruits.push_back({C / P, P});
	}
	
	sort(fruits.begin(), fruits.end());

	cout << solution();
	
	return 0;
}
