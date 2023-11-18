#include <iostream>
using namespace std;

int n, dp[50001];

int main(void)
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> n;

   for (int i = 1; i <= n; i++)
   {
      dp[i] = i;
      for (int j = 1; j * j <= i; j++)
      {
         dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
   }
   cout << dp[n] << "\n";
}