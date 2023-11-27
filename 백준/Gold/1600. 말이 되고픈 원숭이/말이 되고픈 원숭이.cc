#include <iostream>
#include <queue>
#define MAX (201)
using namespace std;

int K, W, H;
int grid[MAX][MAX];
bool visited[MAX][MAX][31];
int knight[8][2] = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, \
                     {1, 2}, {2, 1}, {2, -1}, {1, -2}}; // 말 이동 방식
int monkey[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // 원숭이 이동 방식

int bfs(int x, int y) {
   queue<pair<pair<int, int>, pair<int, int>>> q;
   q.push({{x, y}, {0, K}});
   visited[x][y][K] = true;

   while (!q.empty()) {
      int curX = q.front().first.first;
      int curY = q.front().first.second;
      int cnt = q.front().second.first;
      int k = q.front().second.second;
      q.pop();

      // 도착점에 도달했을 경우
      if (curX == H - 1 && curY == W - 1) return cnt;

      if (k > 0) {
         for (int j = 0; j < 8; j++) { // 말의 이동 방식 적용
            // 다음 x, y 값 설정
            int nextX = curX + knight[j][0];
            int nextY = curY + knight[j][1];

            // 그래프 범위 내에 있는지 확인
            if (nextX < 0 || nextX >= H || nextY < 0 || nextY >= W) continue;
            
            // 장애물이 없고 방문하지 않은 노드일 경우
            if (grid[nextX][nextY] == 0 && !visited[nextX][nextY][k - 1]) {
               q.push({{nextX, nextY}, {cnt + 1, k - 1}});
               visited[nextX][nextY][k - 1] = true;
            }
         }
      }

      for (int i = 0; i < 4; i++) { // 원숭이 이동 방식 적용
         int nextX = curX + monkey[i][0];
         int nextY = curY + monkey[i][1];

         // 그래프 범위 내에 있는지 확인
         if (nextX < 0 || nextX >= H || nextY < 0 || nextY >= W) continue;

         // 장애물이 없고 방문하지 않은 노드일 경우
         if (grid[nextX][nextY] == 0 && !visited[nextX][nextY][k]) {
            q.push({{nextX, nextY}, {cnt + 1, k}});
            visited[nextX][nextY][k] = true;
         }
      }
   }
   return -1;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> K >> W >> H;

   for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
         cin >> grid[i][j];
      }
   }
   cout << bfs(0, 0) << endl;
}