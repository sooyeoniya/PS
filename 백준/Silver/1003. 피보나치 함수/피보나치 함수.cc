// 풀이 시간: 8m02s31
// 시간 복잡도: O(T)
// 공간 복잡도: O(1)
// 틀린 이유: 시간 초과 -> DP로 풀어야 함
#include <iostream>
using namespace std;
int dp[41][2] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    dp[0][0] = dp[1][1] = 1;
    for (int j = 2; j < 41; ++j) {
        dp[j][0] = dp[j - 1][0] + dp[j - 2][0];
        dp[j][1] = dp[j - 1][1] + dp[j - 2][1];
    }
    for (int i = 0; i < T; ++i) {
        int n; cin >> n;
        cout << dp[n][0] << " " << dp[n][1] << "\n";
    }
    return 0;
}