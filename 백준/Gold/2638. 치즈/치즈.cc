#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, ans = 0;
vector<vector<int>> arr, cnt;
vector<vector<bool>> visited;
int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}}; // 4방향

void bfs() {
   queue<pair<int, int>> q;
   q.push({0, 0});
   visited[0][0] = true;

   while (!q.empty()) {
      int curX = q.front().first;
      int curY = q.front().second;
      q.pop();
      
      for (int i = 0; i < 4; ++i) {
         int nextX = curX + dir[i][0];
         int nextY = curY + dir[i][1];

         if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M || visited[nextX][nextY]) continue;

         if (arr[nextX][nextY] == 1) cnt[nextX][nextY]++; // 1일 경우 치즈이므로 cnt++

         if (arr[nextX][nextY] == 0) { // 0일 경우 큐에 넣고 해당 위치 탐색
            q.push({nextX, nextY});
            visited[nextX][nextY] = true;
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> M;
   arr = vector<vector<int>>(N, vector<int>(M));
   for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
         cin >> arr[i][j];
   
   while (1) {
      // 현재 남아있는 치즈가 있는지 확인
      bool isCheese = false;
      for (int i = 0; i < N; ++i) {
         for (int j = 0; j < M; ++j) {
            if (arr[i][j] == 1) 
            { isCheese = true; break; }
         }
      }
      if (!isCheese) break;
      cnt = vector<vector<int>>(N, vector<int>(M, 0)); 
      visited = vector<vector<bool>>(N, vector<bool>(M, false));
      bfs();
      for (int i = 0; i < N; ++i) {
         for (int j = 0; j < M; ++j) {
            if (cnt[i][j] >= 2) arr[i][j] = 0; // 2면 이상 공기와 접촉해있을 경우 치즈 녹임
         }
      }
      ans++; // 1시간 추가
   }
   cout << ans;
   return 0;
}