// 풀이 시간: 51m46ss80
#include <iostream>
#define MAX 100
using namespace std;
int ans = 0, arr[MAX][MAX];

// N: (1, 상단), S: (2, 하단)
int deadlock(int c) {
	int prev = 0, cur = 0, cnt = 0; // 이전 / 현재 자성체, 한 줄의 교착 상태 개수
	bool check = false; // 교착 상태 아님
	for (int i = 0; i < MAX; ++i) {
		cur = arr[i][c];
		if (prev == 1) {
			if (!check && cur == 2) check = true;
			if (check && i == MAX - 1) cnt++;
		}
		if (prev == 2) {
			if (check) {
				if (cur == 1 || i == MAX - 1) { cnt++; check = false; }
			}
		}
		if (cur != 0) prev = cur;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 10;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int x; cin >> x; // 항상 100
		ans = 0;
		for (int i = 0; i < MAX; ++i)
			for (int j = 0; j < MAX; ++j)
				cin >> arr[i][j];
		for (int i = 0; i < MAX; ++i) 
			ans += deadlock(i);
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}