#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int cnt = 0;
char field[12][6];
bool puyoRemoved = false; // 뿌요를 한 그룹 이상 없앴는지 확인
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// 뿌요들 아래로 내리는 함수
void dropPuyo() {
   for (int i = 11; i >= 0; --i) {
      for (int j = 0; j < 6; ++j) {
         if (field[i][j] != '.') {
            int pos = i;
            for (int k = i + 1; k < 12; ++k) {
               if (field[k][j] == '.') pos = k;
               else break;
            }
            if (pos != i) { // 현재 좌표 아래에 빈공간이 있을 경우
               field[pos][j] = field[i][j];
               field[i][j] = '.'; 
            }
         }
      }
   }
}

void bfs(int x, int y) {
   char puyoColor = field[x][y];
   queue<pair<int, int>> q;
   vector<vector<bool>> visited(12, vector<bool>(6, false));
   queue<pair<int, int>> connectedPuyoGroups;

   // 현재 좌표 x, y 설정
   q.push({x, y});
   connectedPuyoGroups.push({x, y}); // 같은 색상 뿌요들의 좌표 저장
   visited[x][y] = true;
   
   // 현재 puyoColor 색상 기준으로 뿌요 탐색
   while(!q.empty()) {
      int curX = q.front().first;
      int curY = q.front().second;
      q.pop();
      
      for (int i = 0; i < 4; i++) {
         int nextX = curX + dir[i][0];
         int nextY = curY + dir[i][1];

         if (nextX < 0 || nextY < 0 || nextX >= 12 || nextY >= 6) continue;

         if (!visited[nextX][nextY] && field[nextX][nextY] == puyoColor) {
            q.push({nextX, nextY});
            connectedPuyoGroups.push({nextX, nextY});
            visited[nextX][nextY] = true;
         }
      }
   }
   // 현재 puyoColor 색상의 뿌요가 4개 이상 연결되었을 경우, 같은 색상의 뿌요들을 전부 터뜨림
   if (connectedPuyoGroups.size() >= 4) {
      puyoRemoved = true;
      while (!connectedPuyoGroups.empty()) {
         int posX = connectedPuyoGroups.front().first;
         int posY = connectedPuyoGroups.front().second;
         connectedPuyoGroups.pop();
         field[posX][posY] = '.';
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   memset(field, '.', sizeof(field));

   for (int i = 0; i < 12; ++i) {
      string s; cin >> s;
      for (int j = 0; j < 6; ++j) 
         field[i][j] = s[j];
   }
   
   while(1) { // 연쇄가 끝날 때까지 반복
      // 현재 필드 전체 탐색
      puyoRemoved = false;
      for (int i = 11; i >= 0; --i) {
         for (int j = 0; j < 6; ++j) {
            if(field[i][j] != '.') bfs(i, j);
         }
      } 
      /* 뿌요 그룹을 하나 이상 없앴을 경우
         하나도 터지지 않았을 경우엔 연쇄 반응이 끝났으므로 break
         여러 그룹이 동시에 터지는 경우를 처리하기 위함 */
      if (puyoRemoved) { cnt++; dropPuyo(); }
      else break;
   }

   cout << cnt << "\n";

   // for (int i = 0; i < 12; ++i) {
   //    for (int j = 0; j < 6; ++j) 
   //       cout << field[i][j] << " ";
   //    cout << "\n";
   // }

   return 0;
}