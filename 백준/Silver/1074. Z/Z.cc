// 풀이 시간: 25m23s36
// 시간 복잡도: O(4^N)
// 공간 복잡도: O(N)

// <풀이 과정>
// 분할 정복, 재귀
// 참고 자료: https://hagisilecoding.tistory.com/14

#include <iostream>
#include <cmath>
using namespace std;
int N, r, c, ans = 0;

void recur(int x, int y, int len) {
    if (r == y && c == x) { cout << ans; return; }
    else if (c < x + len && r < y + len && r >= y && c >= x) {
        recur(x, y, len / 2);
        recur(x + len / 2, y, len / 2);
        recur(x, y + len / 2, len / 2);
        recur(x + len / 2, y + len / 2, len / 2);
    }
    else ans += len * len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> r >> c;
    recur(0, 0, pow(2, N));
    return 0;
}