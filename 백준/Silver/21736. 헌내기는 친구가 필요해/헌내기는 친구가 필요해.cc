#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, people = 0;
int curX, curY; // 도연이 위치
vector<vector<char>> arr;
vector<vector<bool>> visited;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void bfs() {
    queue<pair<int, int>> q;
    q.push({curX, curY});
    visited[curX][curY] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nX = x + dir[i][0];
            int nY = y + dir[i][01];
            if (nX < 0 || nX >= N || nY < 0 || nY >= M || visited[nX][nY] || arr[nX][nY] == 'X') continue;
            if (arr[nX][nY] == 'P') people++;
            visited[nX][nY] = true;
            q.push({nX, nY});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr = vector<vector<char>>(N, vector<char>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'I') { curX = i; curY = j; }
        }
    }
    bfs();
    if (people > 0) cout << people;
    else cout << "TT";
    return 0;
}