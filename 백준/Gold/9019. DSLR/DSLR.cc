#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int T, A, B;
bool visited[10000] = {false, };

void bfs() {
   queue<pair<int, string>> q;
   q.push({A, ""}); // A: 검사할 초기값, "": 출력값, 큐마다 관리할 빈 문자열
   visited[A] = true;

   while(!q.empty()) {
      int cur = q.front().first;
      string ans = q.front().second;
      q.pop();
      if (cur == B) { cout << ans << "\n"; return; } // 현재 문자열이 B와 동일할 경우 출력

      for (int i = 0; i < 4; ++i) { // D: 0, S: 1, L: 2, R: 3
         int next;
         if (i == 0) {
            next = 2 * cur % 10000;
            if (!visited[next]) {
               visited[next] = true;
               q.push({next, ans + "D"});
            }
         }
         else if (i == 1) {
            next = cur - 1 < 0 ? 9999 : cur - 1;
            if (!visited[next]) {
               visited[next] = true;
               q.push({next, ans + "S"});
            }
         }
         else if (i == 2) {
            next = cur % 1000 * 10 + cur / 1000;
            if (!visited[next]) {
               visited[next] = true;
               q.push({next, ans + "L"});
            }
         }
         else if (i == 3) {
            next = cur % 10 * 1000 + cur / 10;
            if (!visited[next]) {
               visited[next] = true;
               q.push({next, ans + "R"});
            }
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> T;
   for (int i = 0; i < T; ++i) {
      memset(visited, false, sizeof(visited));
      cin >> A >> B;
      bfs();
   }
   
   return 0;
}
