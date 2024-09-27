// 풀이 시간: 21:26.79 + α
// 풀이 방법: DP, 비트 마스크
// 시간 복잡도: O(N * M * logK)
// 공간 복잡도: O(N * logk + M)

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 101
#define MAX_M 10001
using namespace std;

// 물건 종류 개수, 가방 최대 무게
int N, M;
int dp[MAX_M];

struct Thing { int V, C, K; }; // 물건 무게, 만족도, 물건 개수
Thing thing[MAX_N];

vector<pair<int, int>> newThing; // V, C 삽입

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  cin >> N >> M;
  for (int i = 0; i < N; ++i)
  	cin >> thing[i].V >> thing[i].C >> thing[i].K;
  	
  for (int i = 0; i < N; ++i) {
  	for (int j = thing[i].K; j > 0; j >>= 1) {
  	  int num = j - (j >> 1);
  	  newThing.push_back({ thing[i].V * num, thing[i].C * num });
  	}
  }
  
  for (int i = 0; i < newThing.size(); ++i)
  	for (int j = M; j >= newThing[i].first; --j)
  	  dp[j] = max(dp[j], dp[j - newThing[i].first] + newThing[i].second);
  
  cout << dp[M];
  return 0;
}