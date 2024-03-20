#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
pair<int, int> pos; // 아기 상어의 위치
int N, sharkSize = 2, fishNum = 0, cnt = 0; // 공간 크기, 아기 상어 크기, 먹은 물고기 수, 시간 초
int arr[21][21] = { 0, }, visited[21][21] = { false, };
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
// dir[i][j] : i번째 줄, j번째 칸, 북서남동

struct Shark {
	int i, j, move; // 현재 아기 상어 좌표(i, j), 이동거리: 초깃값 0
	Shark(int _i, int _j, int _move) : i(_i), j(_j), move(_move) {} // 생성자 정의

	bool operator<(const Shark& other) const {
		// i, j, move 모두 더 작은 값을 우선으로 정렬, 이때 move, i, j 순서대로 우선순위 적용
		if (move != other.move) return move > other.move;
		if (i != other.i) return i > other.i;
		return j > other.j;
	}
};

bool babyShark() {
	priority_queue<Shark> pq;
	pq.push({pos.first, pos.second, 0});
	visited[pos.first][pos.second] = true;

	while (!pq.empty()) {
		int cX = pq.top().i;
		int cY = pq.top().j;
		int cM = pq.top().move;
		pq.pop(); // 가장 거리가 가까우면서 가장 맨 위쪽에서 가장 왼쪽에 있는 물고기 꺼냄

		// 물고기 크기가 아기 상어 크기보다 작으면 먹음
		if (arr[cX][cY] != 0 && sharkSize > arr[cX][cY]) {
			arr[cX][cY] = 0; // 현재 위치를 빈칸으로 변경 (물고기를 먹는다는 의미!)
			cnt += cM; // 아기 상어의 총 이동 거리 갱신
			pos = make_pair(cX, cY); // 현재 좌표로 아기 상어 위치 갱신
			fishNum++; // 먹은 물고기 개수 갱신
			if (fishNum == sharkSize) {
				fishNum = 0; // 먹은 물고기 개수 초기화 **** 중요!! ****
				sharkSize++; // 상어 크기 갱신
			}
			memset(visited, false, sizeof(visited)); // 방문 위치 매번 초기화
			return true;
		}

		for (int i = 0; i < 4; ++i) { // 상하좌우로 다음 좌표 탐색
			int nX = cX + dir[i][0], nY = cY + dir[i][1];
			
			// 공간 크기 범위 초과 또는 방문한 위치일 경우 continue
			if (nX < 0 || nX >= N || nY < 0 || nY >= N || visited[nX][nY]) continue;
			if (arr[nX][nY] > sharkSize) continue;

			pq.push({nX, nY, cM + 1});
			visited[nX][nY] = true; // 방문 처리
		}
	}
	return false; // 먹을 물고기가 없는 경우
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) { // 아기 상어 위치 저장
				pos = make_pair(i, j);
				arr[pos.first][pos.second] = 0; 
				// 아기 상어가 현재 있는 위치를 빈칸으로 설정 (검사 시 헷갈리지 않도록)
				// 따로 상어 좌표를 저장해놨으므로, 물고기를 먹은 위치만 pos값에 갱신해줌
			}
		}
	}
	while(babyShark());
	cout << cnt;
	return 0;
}
