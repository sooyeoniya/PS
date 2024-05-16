// 풀이 시간: 
#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;
int ans = 0;
char arr[2 * MAX][2 * MAX] = { "", };
bool dp[MAX][MAX] = { false, };

bool isPal(int start, int end, int line) {
	/* 
	1. 처음과 끝 문자 동일하고
	2-1. 처음과 끝을 제외한 나머지 부분이 팰린드롬이거나 
	2-2. 처음과 끝 사이에 문자열이 1개만 존재할 경우
	*/
	return (arr[start][line] == arr[end][line] && (dp[start + 1][end - 1] || end - start == 1));
}

void setDP(int line) {
	// dp 배열 리셋 중요
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			dp[i][j] = false;

	// dp 배열 채우기
	for (int dis = 0; dis < MAX; ++dis) {
		for (int begin = 0; begin + dis < MAX; ++begin) {
			if (dis == 0) dp[begin][begin] = true; // 각 문자 하나하나는 모두 팰린드롬
			else if (isPal(begin, begin + dis, line)) { // 팰린드롬인 경우
				dp[begin][begin + dis] = true;
				ans = max(ans, dis + 1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 10;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int num; cin >> num;
		ans = 0;
		for (int i = 0; i < MAX; ++i) {
			for (int j = 0; j < MAX; ++j) {
				cin >> arr[i][j];
				arr[j][i + MAX] = arr[i][j]; // 오른쪽에 1열 붙이기
			}
		}
		for (int i = 0; i < 2 * MAX; ++i) setDP(i);
		cout << "#" << num << " " << ans << "\n";
	}
	return 0;
}