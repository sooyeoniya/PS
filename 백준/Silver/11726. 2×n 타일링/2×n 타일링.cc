// 풀이 시간: 22m27s25
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
// 참고 자료: https://mountrivers.github.io/boj11726/

// <풀이 과정>
// 0 1 2 3 4 5 6 7 8
// 1 2 3 5 8 13 21 34 55
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> dp;
    dp.push_back(1); // 2x1 -> | (한 가지 방법)
    dp.push_back(2); // 2x2 -> ||, = (두 가지 방법)
    for (int i = 2; i < N; ++i)
        dp.push_back((dp[i - 1] + dp[i - 2])%10007);
    cout << dp[N - 1];
    return 0;
}