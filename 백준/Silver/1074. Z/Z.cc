// 풀이 시간: 25m23s36 + 12m(과정 설명 분석)
// 시간 복잡도: O(4^N)
// 공간 복잡도: O(N)

// <풀이 과정>
// 분할 정복, 재귀
// 참고 자료: https://hagisilecoding.tistory.com/14

// 과정 설명 (ChatGPT-4o)
// 문제는 2^N x 2^N 크기의 행렬을 Z자 형태로 순회할 때, (r, c) 위치의 값을 찾는 것입니다. 이를 위해 분할 정복 기법을 사용합니다.

// 예제: N = 2, r = 3, c = 1
// N = 2일 때, 행렬의 크기는 4x4 (2^2 x 2^2)입니다.
// (3, 1) 위치의 값을 찾습니다.

// 초기 호출: recur(0, 0, 4)
// 전체 4x4 행렬을 의미합니다.
// (3, 1)이 이 영역에 포함되므로 네 개의 2x2 서브 영역으로 나눕니다.

// 첫 번째 호출: recur(0, 0, 2)
// 좌상단 2x2 영역입니다.
// (3, 1)은 이 영역에 포함되지 않으므로, ans에 2*2 = 4를 더합니다.
// ans = 4

// 두 번째 호출: recur(2, 0, 2)
// 우상단 2x2 영역입니다.
// (3, 1)이 이 영역에 포함되므로, 다시 네 개의 1x1 서브 영역으로 나눕니다.

// 세 번째 호출: recur(2, 0, 1)
// 좌상단 1x1 영역입니다.
// (3, 1)은 이 영역에 포함되지 않으므로, ans에 1*1 = 1을 더합니다.
// ans = 5

// 네 번째 호출: recur(3, 0, 1)
// 우상단 1x1 영역입니다.
// (3, 1)은 이 영역에 포함되지 않으므로, ans에 1*1 = 1을 더합니다.
// ans = 6

// 다섯 번째 호출: recur(2, 1, 1)
// 좌하단 1x1 영역입니다.
// (3, 1)은 이 영역에 포함되지 않으므로, ans에 1*1 = 1을 더합니다.
// ans = 7

// 여섯 번째 호출: recur(3, 1, 1)
// 우하단 1x1 영역입니다.
// (3, 1)이 정확히 이 위치에 있습니다.
// 정답을 찾았으므로 ans를 출력합니다: 11
// 이와 같은 방식으로 문제를 분할 정복하여 각 서브 영역을 탐색하며 목표 위치를 찾습니다.

#include <iostream>
#include <cmath>
using namespace std;
int N, r, c, ans = 0;

void recur(int x, int y, int len) {
    if (r == y && c == x) { cout << ans; return; }
    else if (c < x + len && r < y + len && r >= y && c >= x) {
        recur(x, y, len / 2); // 1번 영역
        recur(x + len / 2, y, len / 2); // 2번 영역
        recur(x, y + len / 2, len / 2); // 3번 영역
        recur(x + len / 2, y + len / 2, len / 2); // 4번 영역
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
