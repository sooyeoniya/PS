// 풀이 시간: 45m56s12
// 참고 자료
// https://cryptosalamander.tistory.com/58
// https://tear94fall.github.io/lecture/2020/09/16/n-queen-problem.html
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 10
using namespace std;
int N, ans = 0;
int arr[MAX] = { 0, };

// dfs
void nqueen(int num) {
	if (num == N) { // N개의 퀸이 전부 배치됨
		ans++; return;
	}
	for (int i = 0; i < N; ++i) {
		arr[num] = i; // 퀸 위치: (num번째 열, i번째 행)
		bool check = true; // 퀸 배치 가능 여부
		for (int j = 0; j < num; ++j)
			// 같은 행에 다른 퀸이 있는지 확인
			if (arr[j] == arr[num] 
				// 대각선에 다른 퀸이 있는지 확인 (행의 차이 == 열의 차이)
				|| abs(arr[j] - arr[num]) == abs(j - num)) {
				check = false; 
				break;
			}
		if (check) nqueen(num + 1); // 다음 퀸 배치
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> N; 
		memset(arr, 0, sizeof(arr)); // 매번 초기화
		ans = 0;
		nqueen(0); // 0번째 열부터 시작
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}