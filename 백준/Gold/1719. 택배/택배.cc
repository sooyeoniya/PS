#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int n, m;
vector<vector<int>> dist;
vector<vector<int>> map;

void floyedWarshall() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (i == j) continue; // 같은 집하장일 때는 무시
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					map[i][j] = map[i][k]; 
					/*
					* map[1][4]에서는, map[1][3] -> map[3][4]가 최단 경로임
					* 따라서 map[1][3]의 값인 3이 map[1][4]에 들어가야 함
					* 즉, 1번 집하장에서 4번 집하장으로 갈 때는 3번 집하장으로 먼저 이동해야 함
					*/
				}
			}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	dist = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
	map = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = dist[b][a] = c;
		map[a][b] = b; // map[1][2] 에는 2 저장, 1번 집하장에서 2번 집하장으로 갈 때 2번 집하장으로 이동
		map[b][a] = a; // map[2][1] 에는 1 저장
	}

	floyedWarshall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0) cout << "- ";
			else cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}