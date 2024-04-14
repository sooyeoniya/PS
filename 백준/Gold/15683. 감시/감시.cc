#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, ans = 1e9;
vector<vector<int>> arr;
vector<pair<int, int>> cctv; // cctv 좌표
int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}}; // 우상좌하

void watch(int cctvDir, int curX, int curY) {
    int nX = curX + dir[cctvDir][0];
    int nY = curY + dir[cctvDir][1];
    if (nX < 0 || nX >= N || nY < 0 || nY >= M || arr[nX][nY] == 6) return;
    if (arr[nX][nY] == 0) arr[nX][nY] = -1;
    watch(cctvDir, nX, nY);
}

void dfs(int num) {
    if (num == cctv.size()) { // cctv 다 돌았을 경우
        int cnt = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (arr[i][j] == 0) cnt++;
        ans = min(cnt, ans);
        return;
    }
    int curX = cctv[num].first;
    int curY = cctv[num].second;
    int curCCTV = arr[curX][curY];
    vector<vector<int>> temp; // 배열 임시 저장 (백트래킹)
    for (int i = 0; i < 4; ++i) { // 각 cctv를 90도, 4방향으로 돌리기
        temp = arr;
        switch (curCCTV) {
            case 1: // 1번
                watch(i, curX, curY);
                break;
            case 2: // 2번
                watch(i, curX, curY);
                watch((i + 2) % 4, curX, curY);
                break;
            case 3: // 3번
                watch(i, curX, curY);
                watch((i + 1) % 4, curX, curY);
                break;
            case 4: // 4번
                watch(i, curX, curY);
                watch((i + 1) % 4, curX, curY);
                watch((i + 2) % 4, curX, curY);
                break;
            case 5: // 5번
                watch(i, curX, curY);
                watch((i + 1) % 4, curX, curY);
                watch((i + 2) % 4, curX, curY);
                watch((i + 3) % 4, curX, curY);
                break;
        }
        dfs(num + 1);
        arr = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] != 0 && arr[i][j] != 6)
                cctv.push_back({i, j});
        }
    }
    dfs(0);
    cout << ans;
    return 0;
}