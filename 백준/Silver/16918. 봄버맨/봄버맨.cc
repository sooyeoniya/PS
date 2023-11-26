#include <iostream>
#include <vector>
using namespace std;

int R, C, N;
vector<vector<int>> timer; // 폭탄 시간 저장
vector<vector<char>> grid; // 격자판 상태

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void count() {
   for (int t = 2; t <= N; t++) {
      if (t % 2 == 0) { // 폭탄 삽입
         for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
               if (grid[i][j] == '.') {
                  grid[i][j] = 'O';
                  timer[i][j] = t + 3;
               }
            }
         }
      }
      else { // 3초 전에 설치된 폭탄 폭발
         for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
               if (timer[i][j] == t) {
                  for (int k = 0; k < 4; k++) {
                     int nx = i + dx[k];
                     int ny = j + dy[k];

                     if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                     if (grid[nx][ny] == '.') continue;

                     grid[nx][ny] = '.';
                  }
                  grid[i][j] = '.';
                  timer[i][j] = -1;
               }
            }
         }
      }
   }
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> R >> C >> N;

   // 벡터 크기 설정
   timer.resize(R + 1, vector<int>(C + 1, -1));
   grid.resize(R + 1, vector<char>(C + 1, '.'));

   // 초기 상태 설정, 0초, 1초 일 때
   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         cin >> grid[i][j];
         if (grid[i][j] == 'O') timer[i][j] = 0 + 3; // 현재 시간 + 3초
      }
   }

   count();

   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         cout << grid[i][j];
      }
      cout << endl;
   }

}