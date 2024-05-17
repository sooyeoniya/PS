// 풀이 시간: 45m56s12
// 참고 자료
// https://cryptosalamander.tistory.com/58
// https://tear94fall.github.io/lecture/2020/09/16/n-queen-problem.html
#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;
int N, ans = 0;
int arr[MAX] = { 0, };

// dfs
void nqueen(int num) {
	if (num == N) {
		ans++; return;
	}
	for (int i = 0; i < N; ++i) {
		arr[num] = i;
		bool check = true;
		for (int j = 0; j < num; ++j)
			if (arr[j] == arr[num] || abs(arr[j] - arr[num]) == abs(j - num)) {
				check = false; 
				break;
			}
		if (check) nqueen(num + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> N; 
		ans = 0;
		nqueen(0);
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}