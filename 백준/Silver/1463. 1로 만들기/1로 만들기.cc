#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> dp(N + 1, 0);
    dp[1] = 0; // 연산 횟수 저장
    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    cout << dp[N];
    return 0;
}