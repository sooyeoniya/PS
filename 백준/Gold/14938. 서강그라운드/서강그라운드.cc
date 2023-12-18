/**
* 풀이 시간: 2:15:06
* 시간 복잡도: O(n^3 + n^2) = O(n^3) // floyd_warshall()의 3중 for문 + main()의 2중 for문
* 공간 복잡도: O(n^2 + n) = O(n^2) // dist 공간 복잡도 O(n^2) + item 공간 복잡도 O(n)
* 참고 자료: https://velog.io/@yyj8771/Python-백준-14938번-서강그라운드
* [오류 원인]
* 1. 초기화 문제: 모든 거리의 값(dist)이 0으로 초기화 되어 있는 부분 오류
* 		 floyd_warshall 알고리즘에서는 자신으로부터 자신까지의 거리는 0
* 		 그 외의 거리는 무한대(INF)로 초기화해야 함
* 2. 인덱스 문제: 오류의 원인은 인덱스가 0부터 시작하고 있기 때문
* 		 지역의 번호는 1이상 n이하의 정수여야 함
*/
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
