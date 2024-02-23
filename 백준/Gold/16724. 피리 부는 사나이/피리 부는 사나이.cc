#include <iostream>
#include <map>
using namespace std;
int N, M, ans = 0;
char arr[1000][1000];
int visited[1000][1000] = { 0, };
map<char, pair<int, int>> m = {
   {'U', {0, -1}}, {'D', {0, 1}}, // U, D 좌표 이동 수정
   {'L', {-1, 0}}, {'R', {1, 0}}
};

void dfs(int i, int j) {
   // 다음 탐색 좌표 정의
   int ny = i + m[arr[i][j]].second;
   int nx = j + m[arr[i][j]].first;

   visited[i][j] = 1; // 현재 탐색할 값 처리
   if (visited[ny][nx] == 1) ans++; // 다음 탐색 좌표가 0일 경우, 재귀호출을 통해 사이클을 찾은 것이므로 ans++
   if (visited[ny][nx] == 0) dfs(ny, nx); // 방문하지 않은 다음 좌표 탐색
   visited[i][j] = 2; // 이전 동선에서 방문한 값 처리
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> M;

   for (int i = 0; i < N; ++i) {
      string s; cin >> s;
      for (int j = 0; j < M; ++j)
         arr[i][j] = s[j];
   }

   for (int i = 0; i < N; ++i) 
      for (int j = 0; j < M; ++j) 
         if (visited[i][j] == 0) dfs(i, j);

   cout << ans;
   return 0;
}