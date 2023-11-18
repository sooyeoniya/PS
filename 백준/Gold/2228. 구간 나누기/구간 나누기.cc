#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr; // 크기가 n인 1차원 벡터
vector<vector<int>> dp; // 크기가 n * m 2차원 벡터

int solve(int n, int m) {
   if (m == 0) return 0; // 구간
   if (n <= 0) return -1e9; // n의 범위는 1 <= n <= 100이므로 0보다 작을 경우 에러
   if (dp[n][m] != -1) return dp[n][m]; // 메모이제이션(memoization)

   int sum = 0, tmp = 0;
   dp[n][m] = solve(n - 1, m); // 재귀 함수, top-down 방식

   for (int i = n; i > 0; i--) { // n ~ 1 번째 수까지 반복
      sum += arr[i]; // 현재 수부터 마지막 수까지의 합(현재 구간의 합)
      tmp = solve(i - 2, m - 1) + sum; // i - 2: 다음 구간 선택 방지(최소), m - 1: 현재 구간 제외, 현재 구간의 합을 더함
      dp[n][m] = max(dp[n][m], tmp); // 더 큰 값 저장
   }

   return dp[n][m]; // 크기가 n인 배열을 m개의 구간으로 나누었을 때 구간에 속한 수들의 총합의 최댓값
}

int main(void)
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> n >> m;

   // 메모리 재할당, 각 벡터 초기화
   arr.resize(n + 1, 0);
   dp.resize(n + 1, vector<int>(m + 1, -1));
   
   for (int i = 1; i <= n; i++) cin >> arr[i];

   cout << solve(n, m) << "\n";
}