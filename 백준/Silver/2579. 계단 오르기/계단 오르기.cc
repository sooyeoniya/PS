// 풀이 시간: 32m58s50
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)

// <풀이 과정>
// +1 또는 +2
// 연속 3개 계단 밟으면 안 됨 (시작점 미포함, 도착점 포함)
// 마지막 도착점은 반드시 밟기
// 백트래킹 -> 시간 초과 발생
// DP로 풀기
// 참고 자료: https://kimyunseok.tistory.com/34
// 풀이 방법
// 아래 두 가지 경우 max 비교
// 1) 도착점(i) 기준 이전 값(i - 1) 선택하는 경우
//      : 3개 연속 불가능하므로 (i - 2) 선택 불가
//      : 가능한 건 (i - 3)번째 계단의 dp 값
// 2) 도착점(i) 기준 전전 값(i - 2) 선택하는 경우
//      : arr[i] + dp[i - 2] -> 연속 걱정 없이 그냥 이미 계산된 (i - 2)번째 dp 값 더함
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, dp[301] = { 0, };
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    arr = vector<int>(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    for (int i = 2; i < N; ++i)
        dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);
    cout << dp[N - 1];
    return 0;
}