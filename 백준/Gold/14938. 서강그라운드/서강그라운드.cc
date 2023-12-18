#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int n, m, r;
int a, b, l;
vector<vector<int>> dist;
vector<int> item;

void floyd_warshall() { // 지역 이동별 최단 거리 갱신
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r;
	dist = vector<vector<int>>(n, vector<int>(n, INF)); // 모든 거리를 무한대로 초기화
	item = vector<int>(n, 0);

	// 자신으로부터 자신까지의 거리는 0으로 설정
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j) dist[i][j] = 0;

	// 각 지역에 대한 아이템 개수 저장
	for (int i = 0; i < n; i++) cin >> item[i];

	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		// a -> b, b -> a 양방향 통행 가능
		a--; b--; // 인덱스를 0부터 시작하도록 조정
		dist[a][b] = l;
		dist[b][a] = l;
	}

	floyd_warshall();

	int result = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 0; // 각 출발 지역 번호별 아이템 수의 합 저장
		for (int j = 0; j < n; j++) {
			// i -> j 거리가 수색범위(m)보다 작거나 같을 경우
			// i -> j로 이동할 수 있으므로 j에 있는 아이템 수 더함
			if (dist[i][j] <= m) tmp += item[j];
		}
		result = max(result, tmp);
	}
	cout << result << endl;
}