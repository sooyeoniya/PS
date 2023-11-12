// 풀이 시간: 2:00:35
// 시간 복잡도: O(nlogk) - 이진탐색의 범위가 1 ~ k이면서, for문에서 1 ~ n까지의 합을 계산
// 공간 복잡도: O(1) - 입력값 저장 변수와 이진탐색을 위한 변수만 사용하고 있음
// 참고 코드: https://st-lab.tistory.com/281

#include <iostream>
using namespace std;

long n, k; // n*n 2차원 배열 A, 1차원 배열 B에서 k번째 수

// 메모리 사용량과 연산 시간을 줄이기 위해 배열을 생성하지 않고 이진탐색 활용
// 문제 접근법: B[k] = mid 일 때, mid 보다 작거나 같은 원소의 개수가 최소 k개
// 해결 규칙: 각 단 별, mid 값보다 작건나 같은 원소의 개수는 (mid / (단)) -> 이들의 합
int binary_search(long n, long k) {
	long mid = 0, left = 1, right = k; // 배열 B의 인덱스는 1부터 시작
	while (left < right) {
		long sum = 0; // mid 보다 작거나 같은 원소의 전체 개수
		mid = (left + right) / 2; // 임의의 mid 값을 지정 후, 그 값을 기준으로 이진탐색하여 범위 축소

		// 배열 A의 인덱스는 1부터 시작
		// 각 단 별 mid 값보다 작은 원소의 개수의 합을 구하고
		// 그 값을 모두 sum 에 더하여 합계를 구함
		// 이 때, (mid / (단)) 값이 배열의 크기인 n보다 크면 안되기 때문에 min 함수 사용
		for (int i = 1; i <= n; i++) sum += min(mid / i, n);

		// 만약 sum 이 k보다 같거나 크면, right 값을 mid로 설정(값의 범위를 mid 아래로 축소)
		if (sum >= k) right = mid;
		// 만약 sum 이 k보다 작으면, left 값을 mid+1로 설정(값의 범위를 mid 위로 축소)
		else left = mid + 1;
	}
	return left; // sum의 값이 k와 동일할 때, 그 때의 B[k] 값 반환
	// 이때, left는 mid보다 작거나 같은 수의 개수가 k개 이상인 수 중 "가장 작은 수"
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	cout << binary_search(n, k) << "\n";
}
