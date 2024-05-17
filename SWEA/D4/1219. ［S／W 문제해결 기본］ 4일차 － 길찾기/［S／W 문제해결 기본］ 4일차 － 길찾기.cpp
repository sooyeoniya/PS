// 풀이 시간: 20m03s13
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100
using namespace std;
int ans;
vector<vector<int>> arr;
vector<bool> visited;

void bfs() {
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == 99) { ans = 1; return; }
		for (int i = 0; i < arr[cur].size(); ++i) {
			int next = arr[cur][i];
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 10;
	for (int test_case = 1; test_case <= T; ++test_case) {
		ans = 0;
		arr = vector<vector<int>>(MAX);
		visited = vector<bool>(MAX, false);
		int caseNum, N; cin >> caseNum >> N;
		for (int i = 0; i < N; ++i) {
			int a, b; cin >> a >> b;
			arr[a].push_back(b);
		}
		bfs();
		cout << "#" << caseNum << " " << ans << "\n";
	}
	return 0;
}