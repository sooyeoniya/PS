#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int N, M, ans = 1e9;
int m[101] = { 0, }, c[101] = { 0, };
int dp[101][10001] = { 0, };

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> M;
   for (int i = 1; i <= N; ++i) cin >> m[i];
   for (int i = 1; i <= N; ++i) cin >> c[i];

   for (int i = 1; i <= N; ++i) { // 앱
      for (int j = 0; j <= 10000; ++j) { // 비용
         if (c[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
         else dp[i][j] = dp[i - 1][j];
         if (dp[i][j] >= M) ans = min(ans, j);
         // 메모리가 M 이상 되었을 때 최소 비용 갱신
      }
   }

   cout << ans << "\n";
   return 0;
}
