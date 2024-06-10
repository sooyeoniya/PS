// 풀이 시간: 1h03m20s94(고민) + 41m51s66(참고)
// 시간 복잡도: O(N + M) // N: 작업 수, M: 간선(선행 작업 최대 수)
// 공간 복잡도: O(N + M)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
queue<int> q; // 진입 차수가 0인 값 삽입
int dp[10001] = { 0, }; // 총 걸린 작업 시간 저장
int ttime[10001] = { 0, }; // 작업 시간
int inDegree[10001] = { 0, }; // 진입 차수(선행 작업 개수)
vector<int> arr[10001]; // 각 작업(선행)에 대한 후행 작업 번호 저장 (인접 리스트)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> ttime[i] >> inDegree[i]; // 작업 시간, 선행 작업 수
        for (int j = 0; j < inDegree[i]; ++j) {
            int M; cin >> M; // 선행 작업 번호
            arr[M].push_back(i); // 작업 i는 작업 num이 선행되어야 함
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (inDegree[i] == 0) q.push(i); // 진입 차수가 0인 작업 큐에 삽입(선행 작업이 없음)
        dp[i] = ttime[i]; // 각 작업 번호에 해당하는 dp에 해당 작업 시간 추가
    }

    while (!q.empty()) {
        int cur = q.front(); // 현재 작업
        q.pop();
        // 현재 작업(cur)을 선행 작업으로 가지고 있는 작업들 탐색
        for (int i = 0; i < arr[cur].size(); ++i) {
            int next = arr[cur][i];
            inDegree[next]--; // 해당 진입 차수 -1
            // 작업 시간 더 큰 값으로 갱신
            // 이유: 선행 작업이 여러 개일 경우, 해당 경우를 모두 고려해야 하기 때문
            dp[next] = max(dp[next], dp[cur] + ttime[next]);
            if (!inDegree[next]) q.push(next); // 진입 차수가 0인 작업 큐에 삽입
        }
    }
    int ans = -1;
    for (int i = 1; i <= N; ++i)
        ans = max(ans, dp[i]); // 모든 작업을 완료한 최대 시간 출력
    cout << ans;    
    return 0;
}