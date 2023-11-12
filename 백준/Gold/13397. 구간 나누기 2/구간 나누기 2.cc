// 풀이 시간: 3:25:29
// 시간 복잡도: O(nlogS) - S는 배열의 합(sum)을 의미, for문을 통해 0 ~ n까지 선형 탐색
// 공간 복잡도: O(n) - n은 배열의 크기
// 참고 코드: https://leesh111112.tistory.com/356
//            https://ohcode.tistory.com/17
//            https://8156217.tistory.com/46
#include <iostream>
#include <limits.h> // INT_MAX 사용
using namespace std;

int n, m, A[5000]; // 배열 크기 n, 배열을 m개 이하의 구간으로 나눔, 배열 A의 최대 n의 크기는 5000
int sum = 0, ans = INT_MAX; // 무한대 정의, 대략 21억

bool check(int mid) { // 주어진 mid 값을 기준으로 배열을 m개 이하 구간으로 나눌 수 있는지 확인(mid 값이 유효한지 판단)
	int count = 1, maxX = A[0], minX = A[0]; // count를 1(첫 번째 구간), maxX와 minX를 첫 번째 원소 값으로 설정
	for (int i = 0; i < n; i++) { // 배열 전체 순회
		// 현재 구간의 최댓값과 최솟값 구하기
		maxX = max(A[i], maxX); 
		minX = min(A[i], minX);

		// 만약 현재 구간의 '구간의 최댓값'(최댓값-최솟값)이
		// 현재의 구간 점수 최댓값(mid)보다 크면 새로운 구간으로 시작
		// 왜냐하면 구간 점수의 최댓값을 최소로 하는 배열의 분할 방법을 찾는 것이기 때문
		if (maxX - minX > mid) {
			count++; // 새로운 구간 시작
			maxX = minX = A[i];
		}
	}
	// count(구간 개수)가 m(처음에 설정한 구간 개수)보다 많다는 것은
	// mid(현재 구간 점수의 최댓값)가 우리가 구하고자 하는 정답(실제 구간 점수의 최댓값)보다 너무 작다는 뜻
	// 다시 말해 현재 mid 값으로는 배열 m개 이하의 구간으로 나눌 수 없다는 뜻이므로 false 반환
	// 따라서 false를 반환하여 mid 값의 범위를 증가시켜야함
	// 그 반대의 경우에는 mid가 너무 크거나 적당하다는 뜻이므로 true를 반환하여 mid 범위를 감소시키거나 유지하면서 최솟값 갱신
	return m >= count;
}

int binary_search() { // 구간 점수 최댓값 이진 탐색
	// 구간 점수 최댓값(배열에 있는 수의 구간 별 최댓값-최솟값 중 최댓값)은 sum을 절대 넘지 않음
	int mid, left = 0, right = sum;
	while (left <= right) {
		mid = (left + right) / 2; // 임의의 구간 점수 최댓값 설정
		if (check(mid)) {
			right = mid - 1;
			if (mid < ans) ans = mid; // mid의 값(구간 점수 최댓값)이 현재 구간 점수의 최댓값보다 작을 경우 갱신
		}
		else left = mid + 1;
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
		sum += A[i]; // 배열의 모든 원소의 합
	}
	cout << binary_search();
}
