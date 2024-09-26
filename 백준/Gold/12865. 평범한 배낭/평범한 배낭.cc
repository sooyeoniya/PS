// 풀이 시간: 14:55.99 + α
// 풀이 방법: DP
// 시간 복잡도: O(N*K)
// 공간 복잡도: O(N*K)

// [오류]
// 물건은 한 번만 들어갈 수 있는데, 
// 무게 대비 가치가 높을 경우 여러 번 들어가는 이슈 있음
// 반례 참고: https://www.acmicpc.net/board/view/145667
// 수정: 2차원 dp 배열 사용해야 함
// dp[i][w] = i번째 물건까지 고려했을 때, 무게가 w일 때 얻을 수 있는 최대 가치

#include <iostream>
#include <algorithm>
#define MAX_THING 101
#define MAX_WEIGHT 100001
using namespace std;

int N, K; // 물건 수, 최대 무게
int dp[MAX_THING][MAX_WEIGHT];

struct Thing { int W, V; };
Thing thing[MAX_THING];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> thing[i].W >> thing[i].V;
  }

  for (int i = 0; i <= N; ++i)
  	for (int w = 0; w <= K; ++w)
  	  dp[i][w] = 0;

  for (int i = 1; i <= N; ++i) {
  	for (int w = 0; w <= K; ++w) {
  	  // i번째 물건을 선택하지 않는 경우
  	  dp[i][w] = dp[i - 1][w]; // 이전 값 저장
  	  
  	  // i번째 물건을 선택할 수 있는 경우
  	  if (w - thing[i].W >= 0) {
  	  	dp[i][w] = max(dp[i][w], dp[i - 1][w - thing[i].W] + thing[i].V);
  	  }
  	}
  }

  // dp[N][K] = N개의 물건을 고려했을 때, 준서가 버틸 수 있는 최대 무게 K에서의 최대 가치
  cout << dp[N][K];
  return 0;
}