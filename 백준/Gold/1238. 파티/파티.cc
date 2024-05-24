// 풀이 시간: 41m03s40
// 시간 복잡도: O(N(M+N)logN)
// 공간 복잡도: O(E+N) // E는 간선 수

// 풀이 과정
// 다익스트라 알고리즘 -> 우선순위 큐를 사용한 bfs (visited -> dist)
// https://yabmoons.tistory.com/364
// https://hagisilecoding.tistory.com/135

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, X; // 학생 수, 단방향도로개수, X번 마을에서 파티
int ans = 0, temp = 0;
vector<pair<int, int>> arr[1001];
vector<int> dist;

void dijkstra(int start, int end) {
	dist = vector<int>(N + 1, 1e9); // 최대로 초기화
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start}); // 거리, 정점 -> 거리가 앞에 와야 하는 이유는 거리가 작은 순으로 정렬되기 때문
	dist[start] = 0; // 시작 지점 거리 0으로 초기화
	while (!pq.empty()) {
		int curIdx = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();
		if (curIdx == end) { temp = curDist; break; }
		for (int i = 0; i < arr[curIdx].size(); ++i) {
			int nextIdx = arr[curIdx][i].first; // 다음 정점
			int nextDist = curDist + arr[curIdx][i].second; // 다음 정점 거리
			if (dist[nextIdx] > nextDist) { // 방금 계산한 거리가 더 작을 때 갱신
				dist[nextIdx] = nextDist;
				pq.push({ nextDist, nextIdx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> X;
	for (int i = 0; i < M; ++i) {
		int u, v, t; cin >> u >> v >> t;
		arr[u].push_back({ v, t });
	}
	for (int i = 1; i <= N; ++i) {
		dijkstra(i, X); // 가는 길
		int ans1 = temp;
		dijkstra(X, i); // 오는 길
		int ans2 = temp;
		ans = max(ans, ans1 + ans2); // 가장 오래걸리는 학생 소요시간으로 갱신
	}
	cout << ans;
	return 0;
}