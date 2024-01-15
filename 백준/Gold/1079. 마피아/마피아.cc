#include <iostream>
#include <algorithm>
#define MAX 16
using namespace std;

int N, mafia, ans = 0;
int guilt[MAX], R[MAX][MAX];
bool die[MAX] = {false, };

int maximum() {
   // 유죄지수가 같으면 번호가 빠른 사람 먼저 죽음
   int maxNum = -1, maxGuilt = -1;
   for (int i = 0; i < N; i++) {
      // 같으면 그냥 넘김(for문을 통해 번호 빠른 순으로 탐색되므로)
      if (maxGuilt == guilt[i]) continue;
      // 더 큰 유죄지수 발견 시 + 해당 참가자가 살아있을 경우, max 값 갱신
      else if (maxGuilt < guilt[i] && !die[i]) {
         maxGuilt = guilt[i];
         maxNum = i;
      }
   }
   return maxNum;
}

// 은진이가 죽거나 은진이만 살아남았을 때 게임 종료
void game(int cnt, int night) { 

   if (!die[mafia] && cnt == 1) {
      if (night > ans) ans = night;
      return; // 은진이만 살아남은 경우
   }

   if (cnt % 2 == 0) { // 밤
      for (int i = 0; i < N; i++) {
         if (i == mafia || die[i]) continue; // 은진 본인이거나, 이미 죽은 사람일 경우
         
         die[i] = true;
         for (int j = 0; j < N; j++)
            if (!die[j]) guilt[j] += R[i][j];

         game(cnt - 1, night + 1);

         for (int j = 0; j < N; j++)
            if (!die[j]) guilt[j] -= R[i][j];
         die[i] = false;
      }
   } else { // 낮
      int target = maximum();
      if (target == mafia) {
         if (night > ans) ans = night;
         return; // 낮에 은진이가 죽은 경우
      }
      else {
         die[target] = true;
         game(cnt - 1, night);
         die[target] = false;
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> N;
   for (int i = 0; i < N; i++)
      cin >> guilt[i];

   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         cin >> R[i][j];

   cin >> mafia;

   game(N, 0);

   cout << ans << "\n";

   return 0;
}