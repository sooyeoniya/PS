#include <iostream>
using namespace std;
int R, C, T, sum = 0;
int arr[50][50] = { 0, };
int air1 = -1, air2 = -1; // 공기 청정기는 항상 1열이므로 행의 값만 입력 받음
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 4방향

void clean() {
    // 위쪽 공기 청정기 작동 (air1)
    for (int i = air1 - 1; i > 0; --i) // 공기 청정기 세로 라인
        arr[i][0] = arr[i - 1][0];
    for (int j = 0; j < C - 1; ++j) // 맨 상단 라인
        arr[0][j] = arr[0][j + 1];
    for (int i = 0; i < air1; ++i) // 맨 오른쪽 세로 라인
        arr[i][C - 1] = arr[i + 1][C - 1];
    for (int j = C - 1; j > 1; --j) // 공기 청정기 가로 라인
        arr[air1][j] = arr[air1][j - 1];
    arr[air1][1] = 0; // 처음 시작 위치(공기 청정기의 우측)는 0

    // 아래쪽 공기 청정기 작동 (air2)
    for (int i = air2 + 1; i < R - 1; ++i) // 공기 청정기 세로 라인
        arr[i][0] = arr[i + 1][0];
    for (int j = 0; j < C - 1; ++j) // 맨 하단 라인
        arr[R - 1][j] = arr[R - 1][j + 1];
    for (int i = R - 1; i > air2; --i) // 맨 오른쪽 세로 라인
        arr[i][C - 1] = arr[i - 1][C - 1];
    for (int j = C - 1; j > 1; --j) // 공기 청정기 가로 라인
        arr[air2][j] = arr[air2][j - 1];
    arr[air2][1] = 0; // 처음 시작 위치(공기 청정기의 우측)는 0
}

void diff() {
    int tempArr[50][50] = { 0, };
    // 미세먼지 확산
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (arr[i][j] > 0) { // 공기청정기와 미세먼지 없는 곳 제외
                int spreadAmount = arr[i][j] / 5;
                for (int k = 0; k < 4; ++k) { // 4방향 탐색
                    int nX = i + dir[k][0];
                    int nY = j + dir[k][1];
                    if (nX >= 0 && nX < R && nY >= 0 && nY < C && arr[nX][nY] != -1) {
                        tempArr[nX][nY] += spreadAmount; // 확산되는 양 계산하여 더함
                        arr[i][j] -= spreadAmount; // 미세먼지 남은 양 계산
                    }
                }
            }
        }
    }
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            arr[i][j] += tempArr[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(0);
    cin >> R >> C >> T;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) { // 공기청정기 위치 저장
                if (air1 == -1) air1 = i;
                else air2 = i;
            }
        }
    }
    
    for (int i = 0; i < T; ++i) { diff(); clean(); }

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (arr[i][j] > 0) sum += arr[i][j];
    cout << sum;
    return 0;
}