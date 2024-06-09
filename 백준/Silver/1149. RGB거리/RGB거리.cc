// 풀이 시간: 16m14s74
// 시간 복잡도: O(N)
// 공간 복잡도: O(1)
// https://cryptosalamander.tistory.com/84
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int cost[3] = { 0, };
int dp[1001][3] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    dp[0][0] = dp[0][1] = dp[0][2] = 0; // dp 계산을 위한 초기화
    for (int i = 1; i <= N; ++i) {
        cin >> cost[0] >> cost[1] >> cost[2]; // 현재 집을 칠하는 R, G, B 별 비용
        // 인접한 집과 같은 색 사용 불가
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[2];
    }
    cout << min({dp[N][0], dp[N][1], dp[N][2]}); // 모든 집을 칠하는 비용의 최솟값
    return 0;
}