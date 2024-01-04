/**
* 풀이 시간: 1h48m46s
* 시간 복잡도: O(N^2)
* 공간 복잡도: O(N^2)
* 오류 원인
* 1. 처음에 배열 받을 때 입력 오류가 계속 발생 => 한 줄을 문자열로 처리
*	[이전 코드]
* 	for (int j = 0; j < N; j++) {
*		for (int k = 0; k < N; k++) {
*			cin >> grid[j][k];
*		}
*	}
* 참고 자료: https://coooding.tistory.com/32
*/
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define INF 1e6
#define MAX 101
using namespace std;

int N;
int grid[MAX][MAX];
int recoveryTime[MAX][MAX]; // 각 위치별 누적된 최소 복구 시간 값을 저장하는 배열
bool visited[MAX][MAX];
int dist[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 }); // 출발점 큐에 삽입
	visited[0][0] = true; // 첫번째 노드 방문 처리
	recoveryTime[0][0] = 0; // 출발점은 누적 복구 시간이 0

	while (!q.empty()) {
		// 현재 좌표 값
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			// 다음 좌표값 설정
			int nextX = curX + dist[i][0];
			int nextY = curY + dist[i][1];

			// 그래프 범위 내에 있는지 확인
			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;

			/**
			* 다음 좌표를 아직 방문하지 않았거나,
			* (현재 누적 복구 시간 값 + 다음 좌표의 복구 시간 값)이
			* (다음 좌표의 누적 복구 시간 값)보다 작은 경우 갱신
			* 초기에는 (다음 좌표의 누적 복구 시간 값)이 INF로 초기화되어 있음
			* 그 이후에는 누적 복구 시간 값이 더 작은 값으로 계속 갱신됨
			*/
			if (!visited[nextX][nextY] 
				|| recoveryTime[nextX][nextY] > recoveryTime[curX][curY] + grid[nextX][nextY]) {
				recoveryTime[nextX][nextY] = recoveryTime[curX][curY] + grid[nextX][nextY];
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
			}
		}
	}
	return recoveryTime[N - 1][N - 1];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int C;
	cin >> C;
	for (int i = 1; i <= C; ++i) {
		memset(visited, false, sizeof(visited)); // 방문여부 전부 false로 초기화
		memset(recoveryTime, INF, sizeof(recoveryTime)); // 누적 복구 시간 INF로 초기화
		cin >> N;

		// 지도 크기 N 만큼 2차원 배열 형태의 지도 정보 입력
		for (int j = 0; j < N; j++) {
			string s; // 한 줄 전체를 문자열로 받아서 처리
			cin >> s;
			for (int k = 0; k < N; k++) {
				// '0'의 ASCII 코드 값을 빼서 해당 문자에 해당하는 숫자로 변환
				grid[j][k] = s[k] - '0';
			}
		}

		cout << "#" << i << " " << bfs() << "\n";
	}
}