// 메모리: 2112KB, 시간: 68ms

#include <iostream>
#include <queue>
#include <string.h>
#define MAX 301
using namespace std;

bool finish = false;
int N, M, ans = 0;
pair<int, int> joo, bum;
char arr[MAX][MAX];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void bfs() {
    queue<pair<int, int>> q;
    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));

    q.push({ joo.first - 1, joo.second - 1 });
    visited[joo.first - 1][joo.second - 1] = true;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nX = curX + dir[i][0];
            int nY = curY + dir[i][1];

            if (nX < 0 || nX > N || nY < 0 || nY > M || visited[nX][nY]) continue;

            visited[nX][nY] = true;

            if (arr[nX][nY] == '#') { finish = true; return; }
            else if (arr[nX][nY] == '1') arr[nX][nY] = '0';
            else if (arr[nX][nY] == '0') q.push({ nX, nY });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    cin >> joo.first >> joo.second;
    cin >> bum.first >> bum.second;

    string str;
    for (int i = 0; i < N; ++i) {
        cin >> str;
        for (int j = 0; j < M; ++j) {
            arr[i][j] = str[j];
        }
    }

    while (1) {
        ans++;
        bfs();
        if (finish) break;
    }

    cout << ans;
    return 0;
}

// ===================================================
// 메모리: 2252KB, 시간: 4ms

#include <iostream>
#include <queue>
#include <string.h>
#define MAX 301
using namespace std;

bool finish = false;
int N, M, ans = 0;
pair<int, int> joo, bum;
char arr[MAX][MAX];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs() {
  queue<pair<int, int>> q1;
  bool visited[MAX][MAX];
  memset(visited, false, sizeof(visited));

  q1.push({joo.first - 1, joo.second - 1});
  visited[joo.first - 1][joo.second - 1] = true;

  while (1) {
    ans++;
    queue<pair<int, int>> q2;
    while (!q1.empty()) {
      int curX = q1.front().first;
      int curY = q1.front().second;
      q1.pop();

      for (int i = 0; i < 4; ++i) {
        int nX = curX + dir[i][0];
        int nY = curY + dir[i][1];

        if (nX < 0 || nX > N || nY < 0 || nY > M || visited[nX][nY])
          continue;

        visited[nX][nY] = true;

        if (arr[nX][nY] == '#') {
          finish = true;
          return;
        } else if (arr[nX][nY] == '1') {
          q2.push({nX, nY});
          arr[nX][nY] = '0';
        } else if (arr[nX][nY] == '0')
          q1.push({nX, nY});
      }
    }
    q1 = q2;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  cin >> joo.first >> joo.second;
  cin >> bum.first >> bum.second;

  string str;
  for (int i = 0; i < N; ++i) {
    cin >> str;
    for (int j = 0; j < M; ++j) {
      arr[i][j] = str[j];
    }
  }

  bfs();
  cout << ans;
  return 0;
}
