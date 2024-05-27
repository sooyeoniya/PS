// 풀이 시간: 20m06s27
// 시간 복잡도: O(NMH)
// 공간 복잡도: O(NMH)

// <풀이 과정>
// bfs 알고리즘
// 1인 토마토 위치를 전부 queue에 넣고 bfs 수행
// 이때 방향을 총 6개의 방향으로 h도 고려해야함
// 이전 위치 값에서 + 1하여 값 저장
// 출력 시 ans - 1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct TOMATO { int h, r, c; };
int N, M, H, ans = 0;
vector<vector<vector<int>>> arr;
queue<TOMATO> q;
int dir[6][3] = {{0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

void bfs() {
    while(!q.empty()) {
        int cH = q.front().h;
        int cR = q.front().r;
        int cC = q.front().c;
        q.pop();
        for (int i = 0; i < 6; ++i) {
            int nH = cH + dir[i][0];
            int nR = cR + dir[i][1];
            int nC = cC + dir[i][2];
            if (nH < 0 || nH >= H || nR < 0 || nR >= N || nC < 0 || nC >= M || arr[nH][nR][nC] != 0) continue;
            arr[nH][nR][nC] = arr[cH][cR][cC] + 1;
            q.push({nH, nR, nC});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> M >> N >> H;
    arr = vector<vector<vector<int>>>(H, vector<vector<int>>(N, vector<int>(M)));
    bool check = true;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) q.push({i, j, k});
                if (arr[i][j][k] == 0) check = false;
            }
        }
    }
    if (check) { cout << 0; return 0; }
    bfs();
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (arr[i][j][k] == 0) { cout << -1; return 0; }
                ans = max(ans, arr[i][j][k]);
            }
        }
    }
    cout << ans - 1;
    return 0;
}