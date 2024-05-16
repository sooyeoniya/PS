#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, V;
vector<vector<int>> arr;
vector<bool> visited;

void dfs(int num) {
	visited[num] = true;
	cout << num << " ";
	for (int i = 0; i < arr[num].size(); ++i) {
		if (!visited[arr[num][i]]) {
			dfs(arr[num][i]);
		}
	}
}

void bfs() {
	queue<int> q;
	q.push(V);
	visited[V] = true;
	cout << V << " ";
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < arr[cur].size(); ++i) {
			int next = arr[cur][i];
			if (visited[arr[cur][i]]) continue;
			q.push(next);
			visited[next] = true;
			cout << next << " ";
		}
	}
	return;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> V;
	arr = vector<vector<int>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 1; i <= N; ++i) sort(arr[i].begin(), arr[i].end());

	visited = vector<bool>(N + 1, false);
	dfs(V);
	visited = vector<bool>(N + 1, false);
	cout << "\n";
	bfs();
	return 0;
}