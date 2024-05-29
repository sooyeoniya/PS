// 풀이 시간: 14m15s28
// 시간 복잡도: O(N^2)
// 공간 복잡도: O(N^2)
// 풀이 방법: 집이 있는 곳(1) 중에 방문하지 않은 집만 bfs 탐색하여 단지내 집의 수 카운트
// 오류: 각 단지내 집의 수 오름차순 정렬
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
vector<int> num; // 단지별 집의 개수 저장
vector<vector<int>> arr; // 입력 배열
vector<pair<int, int>> one; // 집이 있는 위치
vector<vector<bool>> visited; // 방문 여부 (단지 분리하기 위함)

void bfs(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	while (!q.empty()) {
		int cX = q.front().first;
		int cY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nX = cX + dir[i][0];
			int nY = cY + dir[i][1];
			if (nX < 0 || nX >= N || nY < 0 || nY >= N 
				|| visited[nX][nY] || arr[nX][nY] == 0) continue;
			cnt++;
			visited[nX][nY] = true;
			q.push({ nX, nY });
		}
	}
	num.push_back(cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	arr = vector<vector<int>>(N, vector<int>(N, 0));
	visited = vector<vector<bool>>(N, vector<bool>(N, false));
	for (int i = 0; i < N; ++i) {
		string str; cin >> str;
		for (int j = 0; j < str.size(); ++j) {
			arr[i][j] = str[j] - '0';
			if (arr[i][j] == 1) {
				one.push_back({ i, j });
			}
		}
	}
	for (int i = 0; i < one.size(); ++i) {
		int x = one[i].first, y = one[i].second;
		if (!visited[x][y]) bfs(x, y);
	}
	sort(num.begin(), num.end());
	cout << num.size() << "\n";
	for (int i = 0; i < num.size(); ++i)
		cout << num[i] << "\n";
	return 0;
}