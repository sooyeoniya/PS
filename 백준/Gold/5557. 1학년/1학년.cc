#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr; // 벡터 arr 생성
vector<vector<long long>> dp; // 2차원 벡터 dp 생성

int main(void)
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> n;

   arr.resize(n, 0); // 크기가 n인 벡터를 모두 0으로 초기화
   dp.resize(n, vector<long long>(21, 0)); // 크기가 n x 21인 벡터를 모두 0으로 초기화

   for (int i = 0; i < n; i++) cin >> arr[i];

   // dp[i][j] = "i번째 숫자까지 사용하여 j를 만드는 경우의 수"
   // dp[0][arr[0]] = 1 -> 0번째 숫자를 사용하여 첫 번째 숫자인 arr[0]을 만드는 경우의 수는 1가지
   dp[0][arr[0]] = 1;

   for (int i = 1; i < n - 1; i++) { // 1~(n-2)번째의 숫자까지, 즉 맨 첫번째 숫자와 맨 마지막 숫자를 제외한 모든 값
      for (int j = 0; j <= 20; j++) { // 0 이상 20 이하의 경우만 고려
         if (dp[i - 1][j]) { // 이전 단계에서 숫자 j를 만들 수 있는 경우가 존재하는지 확인
            if (j + arr[i] <= 20) // 현재까지 만든 숫자 j에 현재 숫자 arr[i]를 더했을 때 20 이하인 경우
               dp[i][j + arr[i]] += dp[i - 1][j]; // 이전 단계에서 j를 만드는 경우의 수를 더함
            if (j - arr[i] >= 0) // 현재까지 만든 숫자 j에 현재 숫자 arr[i]를 뺐을 때 0 이상인 경우
               dp[i][j - arr[i]] += dp[i - 1][j]; // 이전 단계에서 j를 만드는 경우의 수를 더함 
         }
      }
   }
   // (n-2)번째의 숫자까지를 사용하여, 마지막 숫자 arr[n-1]를 만드는 경우의 수 출력
   cout << dp[n - 2][arr[n - 1]] << "\n";
}