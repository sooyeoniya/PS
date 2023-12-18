#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, X;
vector<vector<int>> one_way_route; // A -> B 단방향 경로 벡터
vector<int> shortest_route; // 출발도시 X 기준 최단 거리 벡터
vector<int> result; // 최단 거리가 K인 도시

void bfs() {
	int start = X; // 출발 도시 X
	shortest_route[X] = 0; // 출발 도시 X -> X 최단 거리는 항상 0
	queue<int> queue;
	queue.push(X); // 맨 뒤에 X 원소 추가

	while (!queue.empty()) {
		int cur = queue.front(); // 현재 도시
		queue.pop(); // 맨 앞 원소 제거

		for (int i = 0; i < one_way_route[cur].size(); i++) {
			int next = one_way_route[cur][i]; // 현재 도시와 연결된 도시
			if (shortest_route[next] == -1) { // 해당 도시가 탐색 전일 경우(-1)
				shortest_route[next] = shortest_route[cur] + 1; // 거리값: 현재 도시의 + 1
				queue.push(next); // 해당 도시 큐에 삽입 후 재탐색
			}
		}
	}

	// X -> i 까지의 최단 거리가 K일 경우 result 벡터에 삽입
	for (int i = 1; i <= N; i++)
		if (shortest_route[i] == K)
			result.push_back(i);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> X;

	one_way_route = vector<vector<int>>(N + 1);
	shortest_route = vector<int>(N + 1, -1); // 탐색 유무 확인을 위해 -1 초기화
	
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		one_way_route[A].push_back(B); // A -> B 단방향 경로 추가
	}

	bfs();
	
	if(result.size() != 0)
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << endl;
	else cout << -1 << endl;
}