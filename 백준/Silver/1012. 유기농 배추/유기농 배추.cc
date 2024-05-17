#include <iostream>
#include <cstring> // memset
#include <queue>
#define MAX 50
using namespace std;
int T, M, N, K, X, Y, ans;
int arr[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { false, };
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
queue<pair<int, int>> q;

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int nY = y + dir[i][0];
		int nX = x + dir[i][1];
		if (nY < 0 || nY >= N || nX < 0 || nX >= M || visited[nY][nX]) continue;
		if (arr[nY][nX]) dfs(nY, nX);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		q = queue<pair<int, int>>();
		cin >> M >> N >> K;
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		while (K--) {
			cin >> X >> Y;
			arr[Y][X] = 1;
			q.push({ Y, X });
		}
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			if (!visited[y][x]) { dfs(y, x); ans++;}
			q.pop();
		}
		cout << ans << "\n";
	}
	return 0;
}