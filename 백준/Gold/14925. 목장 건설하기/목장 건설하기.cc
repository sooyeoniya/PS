// 풀이 시간: 1h50m22s84 + 1h22m56s53
// 시간 복잡도: O(M * N * L^2)
// 공간 복잡도: O(M * N)
// 참고 자료: https://howudong.tistory.com/212
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int M, N, L = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int dir[3][2] = {{0, 1}, {1, 0}, {1, 1}}; // 탐색할 좌표들

void bfs(int i, int j) {
   /* 현재 좌표 (i, j)에서 (L + 1) 만큼을 더해준 값이 
   배열 범위 자체를 벗어났을 경우에는 탐색할 필요가 없으므로 반환
   (L + 1)을 탐색하는 것이 목적이기 때문 */
   if (i + L + 1 > M + 1 || j + L + 1 > N + 1) return;

   // 현재 좌표 (i, j)부터 한 변의 길이가 (L + 1)이 될 수 있는지 확인
   // 나무(1)나 돌(2)이 하나라도 있을 경우 반환
   for (int k = i; k < i + L + 1; ++k)
      for (int l = j; l < j + L + 1; ++l)
         if (arr[k][l] == 1 || arr[k][l] == 2) return;

   // 현재 좌표 (i, j)부터 정사각형 측정 시작
   int temp = 1; // temp가 1부터 시작하는 이유는 현재 좌표가 0이기 때문에 1x1 정사각형을 만족함
   queue<pair<int, int>> q;
   visited = vector<vector<bool>>(M + 1, vector<bool>(N + 1, false)); // why here?;; IDK
   q.push({i, j});
   visited[i][j] = true;

   while(!q.empty()) { 
      // 정사각형 크기만큼 돌리기
      int size = q.size();
      while(size--) {
         int curX = q.front().first;
         int curY = q.front().second;
         q.pop();

         // 현재 좌표에서 오른쪽, 오른쪽 아래, 아래 부분의 좌표를 탐색
         for (int i = 0; i < 3; ++i) {
            int nextX = curX + dir[i][0];
            int nextY = curY + dir[i][1];

            // 나무(1)나 돌(2)이 있거나, 배열 범위를 벗어났을 경우 반환
            if (nextX > M || nextY > N || arr[nextX][nextY] == 1 || arr[nextX][nextY] == 2) {
               L = max(L, temp);
               return;
            }

            // 방문하지 않은 좌표일 경우 큐에 삽입
            if (!visited[nextX][nextY]) {
               visited[nextX][nextY] = true;
               q.push({nextX, nextY});
            }
         }
      }
      temp++; 
      /* 
      정사각형 크기만큼을 다 돌렸을 때 중간에 return 되지 않고 통과하면 한 변의 길이를 + 1
      다음 큐를 돌면서 더 큰 크기의 정사각형을 만족하는지 검사
      */
   }
   L = max(L, temp); // 더 큰 값을 L에 저장
   return;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> M >> N;
   arr = vector<vector<int>>(M + 1, vector<int>(N + 1, 0));

   for (int i = 1; i <= M; ++i)
      for (int j = 1; j <= N; ++j)
         cin >> arr[i][j];

   // 현재 좌표(i, j)의 값이 0일때 bfs함수 실행
   for (int i = 1; i <= M; ++i)
      for (int j = 1; j <= N; ++j)
         if (arr[i][j] == 0) bfs(i, j);

   cout << L << "\n";
   return 0;
}
