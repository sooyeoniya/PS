// 풀이 시간: 21m28s87(시간 초과) + (추가)
// 시간 복잡도: O((N + M) * logN)
// 공간 복잡도: O(N + M)
// 풀이 방법: 다익스트라 알고리즘, 우선순위 큐

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;
int N, M, st, ed;
int ans[MAX]; // 각 도시별 최소 비용 저장
vector<pair<int, int>> arr[MAX]; // 각 도시별 연결된 도시와 연결 비용

void dijkstra () {
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, st }); // 비용, 출발점
    ans[st] = 0; // 출발 도시 비용 0 -> 추가

    while(!pq.empty()) {
        int curCost = pq.top().first;
        int curPos = pq.top().second;
        pq.pop();

        if (ans[curPos] < curCost) continue; // 이미 계산된 비용이 더 작으면 패스

        for (int i = 0; i < arr[curPos].size(); ++i) {
            int nCost = curCost + arr[curPos][i].second;
            int nPos = arr[curPos][i].first;
            if (nCost < ans[nPos]) {
                ans[nPos] = nCost;
                pq.push({ nCost, nPos });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    memset(ans, 98765432, sizeof(ans));
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c}); // a번째 도시에서 b번째 도시로 가는 데 드는 비용 c
    }
    cin >> st >> ed; // 출발점, 도착점
    dijkstra();
    cout << ans[ed];
    return 0;
}