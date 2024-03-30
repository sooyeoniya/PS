// 유사 문제: 9370 - 미확인 도착지
// 풀이 시간: 
// 시간 복잡도: 
// 공간 복잡도: 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, E, u, v;
int ans = 1e9, f = 0, s = 0, t = 0, sP, tP;
vector<pair<int, int>> arr[801];
vector<int> d;

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int curD = -pq.top().first;
        int curP = pq.top().second;
        pq.pop();
        for (int i = 0; i < arr[curP].size(); ++i) {
            int nD = curD + arr[curP][i].first;
            int nP = arr[curP][i].second;
            if (nD < d[nP]) {
                d[nP] = nD;
                pq.push({-nD, nP});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> E;
    for (int i = 1; i <= N; ++i) vector<pair<int, int>>().swap(arr[i]);
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({c, b});
        arr[b].push_back({c, a});
    }
    cin >> u >> v;
    // u -> v, v -> u 모두 진행
    for (int i = 0; i < 2; ++i) {
        f = 0, s = 0, t = 0;
        d = vector<int>(N + 1, 1e9);
        dijkstra(1); // 출발지에서의 최단 거리
        if (i == 0) {
            f = d[u]; // 첫 번째 구간
            sP = u; // 두 번째 정점
            tP = v; // 세 번째 정점
        } else {
            f = d[v];
            sP = v;
            tP = u;
        }
        d = vector<int>(N + 1, 1e9);
        dijkstra(sP); // 두 번째 정점에서의 최단 거리
        s = d[tP]; // 두 번째 구간
        d = vector<int>(N + 1, 1e9);
        dijkstra(tP); // 세 번째 정점에서의 최단 거리
        t = d[N]; // 세 번째 구간
        ans = min(ans, f + s + t);
    }
    if (ans >= 1e9 || ans < 0) cout << -1;
    else cout << ans;
    return 0;
}