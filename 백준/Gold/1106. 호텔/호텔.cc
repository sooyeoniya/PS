// 풀이 방법: DP
// dp[i]: i명의 고객 수일 때 최소 비용

// [오류 분석]
// 테케랑 반례 전부 맞는데 왜 오답일까?
// 적어도 C명이기 때문에 고객 수가 C보다 큰 경우에 최소 비용이 나올 수 있음
// 따라서, for문의 i의 최대 범위와 dp 크기 재조정
// 마지막에 C명 이상일 경우를 모두 순회하여 최소 비용 출력

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX_N 21
#define INF 1e9
using namespace std;

int C, N; // 최소 고객 수, 도시 개수
vector<int> dp;
pair<int, int> arr[MAX_N] = {};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> C >> N;

  // 홍보 비용, 고객 수
  for (int i = 0; i < N; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  dp = vector<int>(C + 100, INF);
  dp[0] = 0;

  for (int i = 1; i < C + 100; i++) {
    for (int j = 0; j < N; j++) {
      dp[i] = min(dp[i], dp[i - arr[j].second] + arr[j].first);
    }
  }

  int ans = dp[C];
  for (int i = C + 1; i < C + 100; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans;
  return 0;
}