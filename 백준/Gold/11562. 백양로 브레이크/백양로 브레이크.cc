#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, M, K;
int graph[251][251];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	memset(graph, INF, sizeof(graph));
	for (int i = 1; i <= N; i++) graph[i][i] = 0;
	for (int i = 0; i < M; i++) {
		int U, V, B;
		cin >> U >> V >> B;
		graph[U][V] = 0;
		graph[V][U] = 0;
		if (B == 0) graph[V][U] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		}
	}	
	cin >> K;
	for (int i = 0; i < K; i++) {
		int S, E;
		cin >> S >> E;
		cout << graph[S][E] << '\n';
	}
	return 0;
}