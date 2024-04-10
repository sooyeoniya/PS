#include <iostream>
#include <queue>
using namespace std;
int N, M, K, moveDir = 0, score = 0;
int dice[6] = { 3, 5, 4, 2, 1, 6 }; // 처음 주사위 위치의 값 (순서대로 동남서북상하)
int arr[20][20] = { 0, };
int curR = 0, curC = 0; // 현재 위치 (0, 0)
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 동남서북
pair<int, int> nextPos; // 다음 위치

pair<int, int> movePos(int r, int c) { // 현재 위치 이동
    switch (moveDir) {
        case 0: // 동
            c++;
            break;
        case 1: // 남
            r++;
            break;
        case 2: // 서
            c--;
            break;
        case 3: // 북
            r--;
            break;
    }

    // 이동 방향에 칸이 없을 경우 반대 방향으로 설정
    if (r < 0 || r >= N || c < 0 || c >= M) {
        moveDir = (moveDir + 2) % 4; // 반대 방향
        // 좌표 수정 (이미 위에서 이동한 좌표에 한 칸 더 이동)
        switch (moveDir) {
            case 0: // 동
                c += 2;
                break;
            case 1: // 남
                r += 2;
                break;
            case 2: // 서
                c -= 2;
                break;
            case 3: // 북
                r -= 2;
                break;
        }
    }
    return {r, c};
}

void rollDice() { // 주사위 전개도 변경
    int temp;
    switch (moveDir) {
        case 0: // 동
            temp = dice[0];
            dice[0] = dice[4]; // 동 <- 상
            dice[4] = dice[2]; // 상 <- 서
            dice[2] = dice[5]; // 서 <- 하
            dice[5] = temp; // 하 <- 동
            break;
        case 1: // 남
            temp = dice[1];
            dice[1] = dice[4]; // 남 <- 상
            dice[4] = dice[3]; // 상 <- 북
            dice[3] = dice[5]; // 북 <- 하
            dice[5] = temp; // 하 <- 남
            break;
        case 2: // 서
            temp = dice[2];
            dice[2] = dice[4]; // 서 <- 상
            dice[4] = dice[0]; // 상 <- 동
            dice[0] = dice[5]; // 동 <- 하
            dice[5] = temp; // 하 <- 서
            break;
        case 3: // 북
            temp = dice[3];
            dice[3] = dice[4]; // 북 <- 상
            dice[4] = dice[1]; // 상 <- 남
            dice[1] = dice[5]; // 남 <- 하
            dice[5] = temp; // 하 <- 북
            break;
    }
}

void getScore() { // 점수 획득
    int B = arr[curR][curC]; // 주사위가 있는 칸의 정수
    int C = 1; // 이동할 수 있는 칸의 수
    bool visited[20][20] = { false, };
    queue<pair<int, int>> q;
    q.push({curR, curC}); // 현재 위치
    visited[curR][curC] = true;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nX = curX + dir[i][0];
            int nY = curY + dir[i][1];
            if (nX < 0 || nX >= N || nY < 0 || nY >= M || visited[nX][nY]) continue;
            if (B == arr[nX][nY]) {
                visited[nX][nY] = true;
                q.push({nX, nY});
                C++;
            }
        }
    }
    score += B * C;
}

void changeDir() { // 이동 방향 결정
    int A = dice[5]; // 주사위 아랫면 정수
    int B = arr[curR][curC]; // 주사위가 있는 칸의 정수
    if (A > B) moveDir = (moveDir + 1) % 4; // 90도 시계 방향 회전
    else if (A < B) moveDir = (moveDir + 3) % 4; // 90도 반시계 방향 회전
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> arr[i][j];
    while (K--) { // 이동 횟수
        nextPos = movePos(curR, curC);
        curR = nextPos.first;
        curC = nextPos.second;
        rollDice();
        getScore();
        changeDir();
    }
    cout << score;
    return 0;
}