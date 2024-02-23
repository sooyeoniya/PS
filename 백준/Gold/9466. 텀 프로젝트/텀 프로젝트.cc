#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
vector<bool> visited, done;
int T, n, cnt;

void dfs(int j) {
   visited[j] = true;
   if (!visited[arr[j]]) dfs(arr[j]); // 아직 방문하지 않았다면 다음 위치로 이동
   else if (!done[arr[j]]) { // 이미 방문은 했지만 아직 사이클이 아닌 경우
      for (int i = arr[j]; i != j; i = arr[i]) cnt++; // 다른 학생들 전부 카운트
      cnt++; // 본인 카운트
   }
   done[j] = true; // 사이클 형성되었으므로 해당 노드 더 이상 방문하지 않아도 됨
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> T;
   for (int i = 0; i < T; ++i) {
      cnt = 0; cin >> n;
      arr = vector<int>(n + 1);
      visited = vector<bool>(n + 1, false);
      done = vector<bool>(n + 1, false);
      for (int j = 1; j <= n; ++j) cin >> arr[j];
      for (int j = 1; j <= n; ++j) if (!visited[j]) dfs(j);
      cout << n - cnt << '\n';
   }
   return 0;
}