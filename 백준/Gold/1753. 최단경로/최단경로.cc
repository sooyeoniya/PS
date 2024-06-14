// 풀이 시간: 21m10s64
// 시간 복잡도: O((V + E)logV)
// 공간 복잡도: O(V + E)

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 20001
#define INF 987654321
using namespace std;
int V, E, K;
int ans[MAX];
vector<pair<int, int>> arr[MAX];

void dijkstra(int st) {
    fill(ans, ans + MAX, INF); // ans 배열을 INF로 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // greater -> 작은 값부터 출력 
    pq.push({ 0, st }); // 비용, 시작점 (비용 기준 오른차순 정렬이므로 앞에 둠)
    ans[st] = 0; // 사직점 비용 0
    
    while (!pq.empty()) {
        int pos = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for (int i = 0; i < arr[pos].size(); ++i) {
            int nPos = arr[pos][i].first; // 다음 정점
            int nCost = cost + arr[pos][i].second; // 다음 정점까지의 비용
            if(ans[nPos] > nCost) {
                pq.push({nCost, nPos}); // 큐에 삽입
                ans[nPos] = nCost; // ans 배열 갱신
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> V >> E >> K;
    int u, v, w;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> w;
        arr[u].push_back({v, w}); // u -> v 로 가는 간선 가중치 w
    }
    dijkstra(K);
    for (int i = 1; i <= V; ++i) {
        if (ans[i] == INF) cout << "INF\n";
        else cout << ans[i] << "\n";
    }
    return 0;
}