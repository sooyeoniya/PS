#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int W, H;
int grid[102][102];
int eDir[6][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {0, -1} }; // 행이 짝수일 때
int oDir[6][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 1}, {1, 0}, {1, -1} }; // 행이 홀수일 때

int bfs(int x, int y) {
   int sum = 0; // 조명을 장식할 벽면 길이의 합
   queue<pair<int, int>> q; // 큐를 사용하여 탐색
   q.push({x, y}); // 큐에 초기값 삽입

   while(!q.empty()) {
      int curX = q.front().first; // 행 4
      int curY = q.front().second; // 열 8
      q.pop();

      for (int i = 0; i < 6; i++) { // 6방향으로 모두 탐색
         // 행이 짝수일 때 eDir 값, 행이 홀수일 때 oDir 값 삽입
         int nextX = curX + (curX % 2 ? oDir[i][1] : eDir[i][1]);
         int nextY = curY + (curX % 2 ? oDir[i][0] : eDir[i][0]);

         // 다음 탐색할 위치가 그래프 범위 내에 있을 경우
         if (nextX >= 0 && nextX <= H + 1 && nextY >= 0 && nextY <= W + 1) {
            if (grid[nextX][nextY] == 0) { // 건물이 아닌 곳일 경우
               q.push({nextX, nextY}); // 큐에 삽입 후 해당 위치에서 재탐색
               grid[nextX][nextY] = -1; // 방문한 좌표 -1로 설정
            }
            else if (grid[nextX][nextY] == 1) sum++; // 건물인 곳인 경우 벽면 길이 + 1
         }
      }
   }
   return sum;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> W >> H;

   for (int i = 1; i <= H; i++) { // 행 4
      for (int j = 1; j <= W; j++) { // 열 8
         cin >> grid[i][j];
      }
   }
   cout << bfs(0, 0) << endl;
}
