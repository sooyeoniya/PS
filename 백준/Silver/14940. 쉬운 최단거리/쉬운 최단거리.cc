// 풀이 시간: 13m56s61
// 시간 복잡도: O(NM)
// 공간 복잡도: O(NM)

// <풀이 과정>
// bfs로 2번 위치에서부터 4방향을 탐색하며 cnt를 1씩 증가하여 arr 배열 갱신
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, r, c;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<vector<int>> arr;
vector<vector<bool>> visited;

void bfs() {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {r, c}});
    arr[r][c] = 0;
    visited[r][c] = true;
    while (!q.empty()) {
        int cnt = q.front().first;
        int cX = q.front().second.first;
        int cY = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nX = cX + dir[i][0];
            int nY = cY + dir[i][1];
            if (nX < 0 || nX >= N || nY < 0 || nY >= M || arr[nX][nY] == 0 || visited[nX][nY]) continue;
            arr[nX][nY] = cnt + 1;
            visited[nX][nY] = true;
            q.push({cnt + 1, {nX, nY}});
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) { r = i; c = j; }
        }
    }
    bfs();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j] && arr[i][j] != 0) cout << -1 << " ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}