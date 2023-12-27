/**
* 풀이 시간: 35:02
* 시간 복잡도: O(n^3)
* 공간 복잡도: O(n^2)
* 참고 자료: https://velog.io/@yoohoo030/%EB%B0%B1%EC%A4%8011562-%EB%B0%B1%EC%96%91%EB%A1%9C-%EB%B8%8C%EB%A0%88%EC%9D%B4%ED%81%AC
* [오류 원인]: 시간초과
*/
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int n, m, k;
vector<vector<int>> dist;

// 플로이드 워셜 알고리즘을 통해 모든 경로에 대하여 최단 경로 설정
void floydWarshall() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	dist = vector<vector<int>>(n + 1, vector<int>(n + 1, INF)); // 전부 무한대로 초기화

	// 자신으로부터 자신까지의 거리는 0으로 설정
	for (int i = 1; i <= n; i++) dist[i][i] = 0;

	for (int i = 0; i < m; i++) {
		int u, v, b;
		cin >> u >> v >> b;

		// 일방통행일 경우, 기존 경로로 가는 경우에는 경로를 추가할 필요가 없기 때문에 가중치 0
		// 만약 일방통행 길에서 반대로 된 길을 걸었을 때에는 경로를 1개 추가해야 함
		if (b == 0) { dist[u][v] = 0; dist[v][u] = 1; }

		// 양방향일 경우, 각 방향에 대하여 경로를 따로 추가할 필요가 없기 때문에 가중치 0
		if (b == 1) { dist[u][v] = 0; dist[v][u] = 0; }
	}

	floydWarshall();
	cin >> k;

	for (int i = 0; i < k; i++) {
		int s, e;
		cin >> s >> e;
		cout << dist[s][e] << '\n';
	}
}
