#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;
vector<vector<int>> W, C;
int N;

int dfs(int cur_node, int cur_bit) {
   if (cur_bit == (1 << N) - 1) { // 모든 도시를 다 방문했을 경우
      if (W[cur_node][0] == 0) return INF; // 시작 도시로 돌아갈 수 없는 경우, INF 반환
      else return W[cur_node][0]; // 시작 도시로 돌아가는 비용 반환
   }
   
   if (C[cur_node][cur_bit] != -1) return C[cur_node][cur_bit]; // 메모이제이션, 이미 계산된 상태라면 해당 값 반환
   C[cur_node][cur_bit] = INF; // 아직 계산되지 않았다면, 초깃값 INF로 설정

   for (int i = 0; i < N; ++i) {
      if (W[cur_node][i] == 0) continue; // 현재 도시에서 i 도시로 갈 수 없는 경우
      if ((cur_bit & (1 << i)) == (1 << i)) continue; // i 도시를 이미 방문한 경우

      // 현재 상태에서 i 도시로 이동하는 경우의 비용을 계산하고, 최소 비용을 업데이트
      C[cur_node][cur_bit] = min(C[cur_node][cur_bit], W[cur_node][i] + dfs(i, cur_bit | 1 << i));
   }
   return C[cur_node][cur_bit]; // 계산된 최소 비용 반환
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N;
   W = vector<vector<int>>(N, vector<int>(N));
   C = vector<vector<int>>(N, vector<int>(1 << N, -1));
   for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
         cin >> W[i][j];
   cout << dfs(0, 1);
	return 0;
}
