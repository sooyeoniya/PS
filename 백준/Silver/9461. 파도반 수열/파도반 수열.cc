// 풀이 시간: 6m35s11
// 시간 복잡도: O(T)
// 공간 복잡도: O(1)

// <풀이 과정>
// 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, ...
// P[i] = P[i - 1] + P[i - 5];
// 9 = 7 + 2;
// 시간 초과: int -> long long
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    long long P[101] = { 0, };
    P[1] = P[2] = P[3] = 1;
    P[4] = P[5] = 2;
    for (int i = 6; i < 101; ++i)
        P[i] = P[i - 1] + P[i - 5];
    for (int i = 0; i < T; ++i) {
        int N; cin >> N;
        cout << P[N] << "\n";
    }
    return 0;
}