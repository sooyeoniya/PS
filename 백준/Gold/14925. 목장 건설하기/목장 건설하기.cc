#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int M, N, ans = 0;
vector<vector<int>> arr; // 입력 배열
vector<vector<int>> dp; // 정사각형 크기 저장 배열

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> M >> N;
   arr = vector<vector<int>>(M + 1, vector<int>(N + 1));
   dp = vector<vector<int>>(M + 1, vector<int>(N + 1, 0));
   for (int i = 1; i <= M; ++i)
      for (int j = 1; j <= N; ++j)
         cin >> arr[i][j];

   for (int i = 1; i <= M; ++i) {
      for (int j = 1; j <= N; ++j) {
         if (arr[i][j]) continue; // 1 또는 2일 경우 건너뛰기
         // 현재 위치에서 만들 수 있는 가장 큰 정사각형의 한 변의 크기 계산
         dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1; 
         ans = max(ans, dp[i][j]); // 가장 큰 정사각형의 한 변의 크기 갱신
      }
   }
   cout << ans;
   return 0;
}
