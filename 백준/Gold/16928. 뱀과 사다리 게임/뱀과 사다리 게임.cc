#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int arr[101] = {0, };
bool visited[101] = {false, };

void bfs(int pos, int cnt) {
   queue<pair<int, int>> q;
   q.push({pos, cnt});
   visited[pos] = true;

   while(!q.empty()) {
      int pos = q.front().first;
      int cnt = q.front().second;
      q.pop();

      if (pos == 100) { cout << cnt; break; }

      for (int i = 1; i <= 6; ++i) {
         int next = pos + i;
         if (next <= 100 && !visited[next]) {
            visited[next] = true;
            if (arr[next] != 0) next = arr[next];
            q.push({next, cnt + 1});
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> M;
   
   for (int i = 0; i < N; ++i) {
      int x, y; cin >> x >> y;
      arr[x] = y;
   }
   for (int i = 0; i < M; ++i) {
      int u, v; cin >> u >> v;
      arr[u] = v;
   }
   bfs(1, 0);
   return 0;
}