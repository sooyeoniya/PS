// 풀이 시간: 32m00s48
// 시간 복잡도: O(NM)
// 공간 복잡도: O(NM)

// <풀이 과정>
// bfs 알고리즘 적용
// 오류: 예제 4) 1이 여러개일 때에는 어떻게 해야하지?
// -> 큐에 그냥 익은 토마토(1)를 한 번에 다 넣어버리고 bfs 돌리기
// -> 그러면 bfs 병렬적으로 수행됨
#include <iostream>
#include <queue>
using namespace std;
int M, N, ans = 0;
int arr[1001][1001] = { 0, };
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int cX = q.front().first;
        int cY = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nX = cX + dir[i][0];
            int nY = cY + dir[i][1];
            if (nX < 0 || nX >= N || nY < 0 || nY >= M || arr[nX][nY] != 0) continue;
            arr[nX][nY] = arr[cX][cY] + 1; // 이전 값에서 1일씩 더해서 저장
            q.push({nX, nY});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> M >> N;
    bool check = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) q.push({i, j});
            if (arr[i][j] == 0) check = false; // 안익은 토마토가 하나라도 있으면
        }
    }
    if (check) { cout << 0; return 0; } // 모든 토마토가 익어있는 상태면 0
    bfs();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == 0) { // 익지 않은 토마토가 있으면
                cout << -1; return 0;
            }
            ans = max(ans, arr[i][j]); // 가장 큰 값으로 갱신
        }
    }
    cout << ans - 1;
    return 0;
}