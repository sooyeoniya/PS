#include <iostream>
using namespace std;

int n, dp[50001]; // 1 <= n <= 50000

int main(void)
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> n;

   for (int i = 1; i <= n; i++)
   {
      dp[i] = i; // 1부터 n까지의 수에 대해 dp 배열 초기화, 각 수는 최소한 그 수만큼의 1의 제곱으로 나타낼 수 있기 때문
      // 각 i에 대하여 가능한 모든 제곱수 j*j를 뺀 값에 대한 dp값(해당 값에서의 제곱수의 최소 개수) 조회
      for (int j = 1; j * j <= i; j++) // 
      {
         // 현재 dp[i]와 비교하여 더 작은 값으로 설정
         // "dp[i - j * j] + 1"에서 1을 더해주는 이유는 현재 뺀 제곱수(j*j)의 경우의 수를 하나 더해준 것
         dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
   }
   // 합이 자연수 n과 같게 되는 제곱수들의 최소 개수 출력
   cout << dp[n] << "\n";
}
