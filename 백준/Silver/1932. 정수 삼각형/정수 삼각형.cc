// 풀이 시간: 21m34s63(초기 코드 -> 오답) + 12m45s87(다시 풀기)
// 시간 복잡도: O(N^2)
// 공간 복잡도: O(N^2)
// 풀이 참고: https://gaeunhan.tistory.com/67

#include <iostream>
#include <algorithm>
using namespace std;
int arr[501][501] = { 0, };
int dp[501][501] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> arr[i][j];

    dp[1][1] = arr[1][1]; // 맨 위층 삽입
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1) dp[i][j] = dp[i - 1][j] + arr[i][j]; // 왼쪽 끝 라인 타기, dp[2][1] = dp[1][1] + arr[2][1];
            else if (j == i) dp[i][j] = dp[i - 1][j - 1] + arr[i][j]; // 오른쪽 끝 라인 타기, dp[2][2] = dp[1][1] + arr[2][2];
            else dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j]); // 대각선 왼쪽 위 vs 대각선 오른쪽 위
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; ++i)
        sum = max(sum, dp[N][i]);
    cout << sum;
    return 0;
}