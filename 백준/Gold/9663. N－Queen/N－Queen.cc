// 풀이 시간: 7m54s84
#include <iostream>
#include <algorithm>
#define MAX 15
using namespace std;
int N, ans = 0;
int arr[MAX] = { 0, };

void nqueen(int num) {
	if (num == N) { ans++; return; }
	for (int i = 0; i < N; ++i) {
		arr[num] = i;
		bool check = true;
		for (int j = 0; j < num; ++j) {
			if (arr[j] == arr[num] || abs(arr[j] - arr[num]) == abs(j - num)) {
				check = false; break;
			}
		}
		if (check) nqueen(num + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	nqueen(0);
	cout << ans;
	return 0;
}