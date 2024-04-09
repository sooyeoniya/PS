#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, cnt = 0, up = 0, down;
vector<int> A; // 각 벨트 위치의 내구도
vector<bool> R; // 각 위치별 로봇 유무

void rotateAll() {
    // 전체 회전한다는 것은 올리는 위치와 내리는 위치가 이동한다는 것
    up = up - 1 >= 0 ? up - 1 : 2 * N - 1;
    down = down - 1 >= 0 ? down - 1 : 2 * N - 1;
    R[down] = false; // 내리는 위치의 로봇 제거
}

void rotateRobot() {
    // 가장 먼저 올린 로봇은 down 위치와 가깝기 때문에 down에서부터 up까지 차례대로 진행
    int idx = down;
    for (int i = 0; i < N; ++i) {
        int next = idx; // 다음 위치
        idx = idx - 1 >= 0 ? idx - 1 : 2 * N - 1; // 현재 위치
        // 현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며, 다음 위치의 내구도가 1 이상인 경우 로봇 이동
        if (R[idx] && !R[next] && A[next] >= 1) {
            R[next] = true;
            R[idx] = false;
            A[next]--;
        }
        R[down] = false; // 내리는 위치의 로봇 제거
    }
}

void loadRobot() {
    if (A[up] >= 1) { // 올리는 위치의 내구도가 1 이상인 경우 로봇 올림
        R[up] = true;
        A[up]--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    down = N - 1; // 내리는 위치 설정
    A = vector<int>(2 * N, 0);
    R = vector<bool>(2 * N, false);
    for (int i = 0; i < 2 * N; ++i) cin >> A[i];

    // 내구도가 0인 칸의 개수가 K개보다 작을 때만 반복
    while (count(A.begin(), A.end(), 0) < K) {
        cnt++; // 단계 먼저 추가
        rotateAll(); // 벨트와 로봇 회전
        if (cnt > 1) rotateRobot(); // 로봇 회전 (첫 번째 단계에서는 로봇이 없으므로 생략)
        loadRobot(); // 로봇 올리기
    }
    cout << cnt;
    return 0;
}