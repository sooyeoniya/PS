#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 1e9;

int N, W;
double M;
vector<bool> visited;
vector<double> dist;
vector<pair<double, double>> xy;
vector<vector<double>> node;

// 방문하지 않은 노드 중 가장 dist 값이 작은 노드의 인덱스 반환
int findShortestNode() {
	int minDist = INF, minIdx = -1;

	for (int i = 1; i <= N; i++) {
		if (visited[i] == true) continue;
		if (dist[i] < minDist) {
			minDist = dist[i];
			minIdx = i;
		}
	}
	return minIdx;
}

void dijkstra() { 
	for (int i = 1; i <= N; i++) {
		dist[i] = node[1][i];
	}
	dist[1] = 0;
	visited[1] = true;
	for (int i = 1; i < N - 1; i++) {
		int newNode = findShortestNode();
		if (newNode == -1) break;
		visited[newNode] = true;

		for (int j = 1; j <= N; j++) {
			if (visited[j] == true) continue;
			if (dist[j] > dist[newNode] + node[newNode][j])
				dist[j] = dist[newNode] + node[newNode][j];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> W >> M;
	visited = vector<bool>(N + 1, false);
	dist = vector<double>(N + 1, INF);
	xy = vector<pair<double, double>>(N + 1);
	node = vector<vector<double>>(N + 1, vector<double>(N + 1, INF));

	// 각 좌표별 발전소 값 초기화
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		xy[i] = make_pair(x, y);
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			double x = abs(xy[i].first - xy[j].first);
			double y = abs(xy[i].second - xy[j].second);

			// 두 발전소 사이의 전선의 길이가 M을 초과하면 안됨
			if (sqrt(x * x + y * y) <= M)
				node[i][j] = node[j][i] = sqrt(x * x + y * y);
		}
	}

	// 현재 남아있는 전선이 잇고 있는 두 발전소
	for (int i = 0; i < W; i++) {
		int a, b;
		cin >> a >> b;
		node[a][b] = node[b][a] = 0; // 이미 연결된 발전소들의 거리는 0으로 설정
	}

	dijkstra();
	cout << (long)(dist[N] * 1000) << endl;
}