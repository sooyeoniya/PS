// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
// 참고 자료: https://ongveloper.tistory.com/247

// <풀이 과정>
// 2x3 직사각형 => dp[3] = dp[2] + dp[1] + dp[1]
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> dp;
    dp.push_back(1); // 2x1
    dp.push_back(3); // 2x2
    for (int i = 2; i < N; ++i)
        dp.push_back((dp[i - 1] + dp[i - 2] * 2)%10007);
    cout << dp[N - 1];
    return 0;
}