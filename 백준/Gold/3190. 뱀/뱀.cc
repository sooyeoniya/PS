#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int N, K, L, X, C;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 상,우,하,좌 {행(x), 열(y)}
vector<vector<int>> arr; // 0: 빈공간, 1: 사과, 2: 뱀
deque<pair<int, int>> trans;

void dummy() {
   int d = 1, t = 0;
   arr[0][0] = 2;
   deque<pair<int, int>> snake;
   snake.push_back(make_pair(0, 0)); // 시작 위치
   while (1) {
      t++;
      /* 다음 위치 = 현재 뱀의 머리 + 방향 이동 */
      int nextX = snake.front().first + dir[d][0]; 
      int nextY = snake.front().second + dir[d][1];
      if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || arr[nextX][nextY] == 2) break;
      if (arr[nextX][nextY] == 0) { // 사과가 없을 경우 뱀 꼬리 하나 제거
         arr[snake.back().first][snake.back().second] = 0;
         snake.pop_back();
      }
      snake.push_front(make_pair(nextX, nextY)); // 다음 위치에 뱀 머리 추가
      arr[nextX][nextY] = 2;

      /* 방향 전환 */
      if (!trans.empty() && trans.front().first == t) {
         d = (d + trans.front().second) % 4; // 4가 넘어갈 경우 조정
         if (d < 0) d += 4; // 음수일 경우 조정
         trans.pop_front(); // 맨 앞의 값 삭제
      }
   }
   cout << t;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> K;
   arr = vector<vector<int>>(N, vector<int>(N, 0));
   for (int i = 0; i < K; ++i) {
      int x, y; cin >> x >> y;
      arr[x - 1][y - 1] = 1; // 좌표는 0부터 시작하므로 각각 -1
   }
   cin >> L;
   for (int i = 0; i < L; ++i) {
      int x; char c; cin >> x >> c;
      if (c == 'D') trans.push_back(make_pair(x, 1));
      if (c == 'L') trans.push_back(make_pair(x, -1));
   }
   dummy();
   return 0;
}
