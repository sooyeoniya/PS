#include <iostream>
using namespace std;
int N, M, K, R, C;
bool check = false;
int arr[40][40] = { 0, };
int temp[10][10] = { 0, };

void stick() {
    // 전체 위치 순회하여 붙일 수 있는 공간 찾아 붙이기
    for (int i = 0; i <= N - R; ++i) { 
        for (int j = 0; j <= M - C; ++j) {
            bool flag = true;
            for (int r = 0; r < R; ++r)
                for (int c = 0; c < C; ++c) {
                    if (temp[r][c] == 1 && arr[r + i][c + j] == 1) 
                        { flag = false; break; } // 이미 스티커가 붙여있을 경우 종료
                }
            if (flag) { // 해당 스티커 붙이기
                check = true;
                for (int r = 0; r < R; ++r)
                    for (int c = 0; c < C; ++c)
                        if (temp[r][c] == 1)
                            arr[r + i][c + j] = temp[r][c];
                return;
            }
        }
    }
}

void rotate() {
    for (int i = 0; i < 4; ++i) { // 0도, 90도, 180도, 270도
        stick();
        if (check) break; // 스티커 붙었을 경우 회전 종료
        int T = R; R = C; C = T; // R <-> C
        int rotated[10][10] = { 0, };
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                rotated[i][C - j - 1] = temp[j][i];
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                temp[i][j] = rotated[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
        cin >> R >> C;
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                cin >> temp[r][c];
        check = false; // 스티커 부착 여부
        rotate(); // 스티커 회전
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (arr[i][j] == 1) cnt++;
    cout << cnt;
    return 0;
}