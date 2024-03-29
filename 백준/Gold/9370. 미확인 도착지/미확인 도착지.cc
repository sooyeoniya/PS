#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int T, n, m, t, s, g, h;
vector<int> ans, dis; // 목적지 후보, 각 인덱스까지의 최단거리
vector<pair<int, int>> graph[2001];

void dijkstra(int start) {
    dis[start] = 0; // 기준이 되는 출발지 거리 0
    priority_queue<pair<int, int>> pq;
    pq.push({0, start}); // 이동거리, 현재 위치

    while(!pq.empty()) {
        int curDis = -pq.top().first; // 이동거리 (음수화)
        int curPos = pq.top().second; // 현재 위치
        pq.pop();
        for (int i = 0; i < graph[curPos].size(); ++i) { // 인접한 정점의 개수만큼 순회
            int nDis = curDis + graph[curPos][i].first;
            int nPos = graph[curPos][i].second;
            // 현재 위치를 거쳐서 다음 위치로 가는 거리가 더 짧은 경우 최단 경로 갱신
            if (nDis < dis[nPos]) {
                dis[nPos] = nDis;
                pq.push({-nDis, nPos}); // 짧은 이동거리부터 우선순위 큐에 넣어지도록 음수화
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for (int testCase = 0; testCase < T; ++testCase) {
        cin >> n >> m >> t >> s >> g >> h;
        // graph 초기화 (size() 함수 사용을 위한 graph 선언 및 초기화 방법)
        for (int i = 1; i <= n; i++) vector<pair<int, int>>().swap(graph[i]);
        ans = vector<int>(n + 1, 0);
        dis = vector<int>(n + 1, 1e9); // 최단 경로 비교를 위해 무한대로 초기화

        int first, second, thrid, thridPos; // 각 구간별 최단 경로 값, 3번째 위치

        for (int i = 0; i < m; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            // g, h 경로는 홀수화, 나머지 짝수화
            if ((a == g && b == h) || (a == h && b == g)) second = d; // 두 번째 구간 값
            // 양방향 도로
            graph[a].push_back({d, b});
            graph[b].push_back({d, a});
        }

        dijkstra(s);

        if (dis[g] < dis[h]) { // g가 h보다 가깝다면 
            first = dis[g]; // 첫 번째 구간 값
            thridPos = h; // 3번째 위치
        }
        else {
            first = dis[h]; // 첫 번째 구간 값
            thridPos = g; // 3번째 위치
        }

        for (int i = 0; i < t; ++i) {
            int x; cin >> x;
            ans[x] = dis[x]; // 출발점 s에서부터 목적지 후보 x까지의 최단 경로 값 전부 저장
        }

        dijkstra(thridPos); // 3번째 위치부터 시작하는 최단 경로 값

        for (int i = 1; i <= n; ++i) { // 홀수일 때만 출력 (오름차순)
            thrid = dis[i]; // 세 번째 구간 값
            if (ans[i] == first + second + thrid) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}