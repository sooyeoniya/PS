#include <iostream>
#include <map>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
int N, cnt = 0, d, g = 0; // N, 출력 값, 시작 방향, 세대
deque<int> direct; // 특정 드래곤 커브에 대한 방향 덱
bool arr[101][101] = { false, }; // 드래곤 커브 좌표인지 확인
map<int, pair<int, int>> dir = {
   {0, {1, 0}}, {1, {0, -1}},
   {2, {-1, 0}}, {3, {0, 1}}
}; // 방향: 0, 1, 2, 3
vector<pair<int, int>> save; // 지나온 좌표 저장 값

/* 0<= curX <= 100, 0 <= curY <= 100 일 때만 arr을 true로 변경 */
void constraint(int curX, int curY) {
   if (curX >= 0 && curX <= 100 && curY >= 0 && curY <= 100)
      arr[curX][curY] = true;
}

int reverse(int d) { // 반대 방향의 -1 한 값을 반환
   if (d == 0) return (2 - 1);
   if (d == 1) return (3 - 1);
   if (d == 2) return (4 - 1);
   if (d == 3) return (1 - 1);
}

/* 현재 좌표를 기준으로 현재 좌표와
(0, 1), (1, 0), (1, 1)을 더한 좌표 값이 true인 경우 cnt++ */
void check() {
   for (int i = 0; i < 101; ++i) {
      for (int j = 0; j < 101; ++j) {
         if (i + 1 >= 101 || j + 1 >= 101) continue;
         if (arr[i][j] && arr[i + 1][j] 
            && arr[i][j + 1] && arr[i + 1][j + 1]) {
            cnt++;
         }
      }
   } 
}

void dragon() {
   int tempG = 0; // 현재 세대
   do {
      /* 아직 0세대인 경우, 시작 방향(d)을 활용하기 위해 따로 조건문 추가 */
      if (tempG == 0) {
         int x = save.back().first;
         int y = save.back().second;
         int curX = x + dir.find(d)->second.first;
         int curY = y + dir.find(d)->second.second;
         save.push_back(make_pair(curX, curY));

         constraint(curX, curY);

         /* 시작 방향(d)를 이용해 다음 방향을 direct에 삽입 */
         direct.push_front(reverse(d));
      }
      else {
         /* direct에 있는 방향을 하나씩 탐색하면서, 
         save의 마지막 좌표에 해당 방향 좌표 값을 더하여 좌표 이동 후 저장 */
         for (int dirValue : direct) {
            int x = save.back().first;
            int y = save.back().second;
            int curX = x + dir.find(dirValue)->second.first;
            int curY = y + dir.find(dirValue)->second.second;
            save.push_back(make_pair(curX, curY));

            constraint(curX, curY);
         }

         /* direct를 앞에서부터 탐색하면서 reverse() 함수로 다음 방향들을 앞에서부터 차례대로 저장 후, 
         newDirect의 앞에서부터 하나씩 빼내어 direct 앞에 하나씩 추가함 */
         deque<int> newDirect;
         for (int dirValue : direct) newDirect.push_back(reverse(dirValue));
         for (int dirValue : newDirect) direct.push_front(dirValue);
      }
      tempG++;
   } while (tempG <= g); // 세대를 모두 생성하면 종료
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N;
   for (int i = 0; i < N; ++i) {
      /* 초기화 */
      direct = deque<int>();
      save.clear();

      /* 입력: 시작 점(x, y), 시작 방향(d), 세대(g) */
      int x, y;
      cin >> x >> y >> d >> g;
      save.push_back(make_pair(x, y));
      arr[x][y] = true;

      /* 드래곤 커브 실행 */
      dragon();
   }

   /* 정사각형 개수 카운트 및 출력 */
   check(); cout << cnt;
	return 0;
}