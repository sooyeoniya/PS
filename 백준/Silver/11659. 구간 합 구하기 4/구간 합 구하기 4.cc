// 풀이 시간: 5m
// 시간 복잡도: O(N + M)
// 공간 복잡도: O(N)
// 참고 자료: https://velog.io/@hayounsong/%EB%B0%B1%EC%A4%80-11659%EB%B2%88%EA%B5%AC%EA%B0%84-%ED%95%A9-%EA%B5%AC%ED%95%98%EA%B8%B0-4-C-%ED%92%80%EC%9D%B4

// <풀이 과정>
// 그냥 풀면 시간 초과 남
// DP로 풀어서 시간 초과 해결
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<long long> arr(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        long long a; cin >> a;
        arr[i] = arr[i - 1] + a; // 누적합 저장
    }
    for (int t = 0; t < M; ++t) {
        int i, j; cin >> i >> j;
        cout << arr[j] - arr[i - 1] << "\n"; // j번째 값에서 i-1번째 값 빼줌 (i~j 사이 누적합 저장)
    }
    return 0;
}