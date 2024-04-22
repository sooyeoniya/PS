// 풀이 시간: 7m20s73
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
#include <iostream>
using namespace std;
int arr[10] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, K, ans = 0;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = N - 1; i >= 0; --i) {
        if (arr[i] <= K) {
            ans += K / arr[i];
            K %= arr[i];
        }
    }
    cout << ans;
    return 0;
}