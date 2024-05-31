// 풀이 시간: 33m52s43
// 시간 복잡도: O(NlogN + NlogM)
// O(NlogN) - sort 함수
// O(NlogM) - 이진탐색 while문 O(logM) * for문 O(N)
// 공간 복잡도: O(N)
// 풀이 방법: 이분탐색 -> 절단할 높이 기준
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N, M, ans = 0; // 타입 주의
vector<long long> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	arr = vector<long long>(N);
	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr.begin(), arr.end()); // 오름차순 정렬
	long long left = 0, right = arr[N - 1]; // 길이 전체
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long cnt = 0; // 절단된 나무들 길이의 합
		for (int i = 0; i < N; ++i)
			if (arr[i] > mid) // 설정 높이보다 큰 나무의 경우
				cnt += (arr[i] - mid);
		if (cnt >= M) { // M이 넘어가는 경우 높이를 더 올림
			ans = mid;
			left = mid + 1;
		}
		else { // 절단할 높이 내림
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}