#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 회의시간을 끝나는 순서 기준으로 오름차순으로 정렬,
   끝나는 시간이 같다면 시작시간 기준으로 오름차순 정렬*/
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main() {
	pair <int,int> time[100000];
	int n;
	int count = 1;
	int start_time, end_time;
	int end;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> start_time >> end_time;
		time[i].first = start_time;
		time[i].second = end_time;
	}

	sort(time, time + n, compare);

	end = time[0].second;
	for (int i = 1; i < n; i++) {
		if (time[i].first >= end) {
			count++;
			end = time[i].second;
		}
	}
	cout << count;


}