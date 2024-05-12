// 풀이 시간: 30m
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
// 참고 자료: https://danidani-de.tistory.com/4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> dp(N + 1, 0);
    dp[1] = 0; // 연산 횟수 저장
    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + 1; // 1을 뺐을 때의 연산 횟수 + 1
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1); // 3으로 나누어 떨어질 때 3으로 나누면서 연산 횟수 + 1
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1); // 2로 나누어 떨어질 때 2로 나누면서 연산 횟수 + 1
    }
    cout << dp[N];
    return 0;
}
