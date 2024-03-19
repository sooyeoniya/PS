#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, r, c, d, cnt = 0;
int arr[51][51] = { 0, };
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; 
// dir[i][j] : 북 동 남 서, i번째 줄, j번째 칸

void cleanRoom(int r, int c) {
	if (arr[r][c] == 0) { cnt++; arr[r][c] = 2; } // 현재 칸 (r, c) 청소
	bool isEmpty = false;
	for (int i = 0; i < 4; ++i) // 주변 4칸 검사
		if (arr[r + dir[i][0]][c + dir[i][1]] == 0) 
			isEmpty = true;
	if (!isEmpty) { // 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
		// 바라보는 방향의 뒤쪽 칸으로 후진 가능한 경우
		if (arr[r + dir[(d + 2) % 4][0]][c + dir[(d + 2) % 4][1]] != 1)
			cleanRoom(r + dir[(d + 2) % 4][0], c + dir[(d + 2) % 4][1]);
		else return; // 뒤쪽 칸이 벽이라 후진이 불가능한 경우 작동 멈춤
	}
	else { // 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
		// 반시계 90도 회전 및 앞쪽 칸이 청소되지 않은 빈칸인 경우 전진
		while(1) {
			d = ((d - 1) % 4 < 0) ? ((d - 1) % 4 + 4) : ((d - 1) % 4); // 음수인 경우 양수로 조정
			if (arr[r + dir[d][0]][c + dir[d][1]] == 0) break;
		}
		cleanRoom(r + dir[d][0], c + dir[d][1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];
	cleanRoom(r, c);
	cout << cnt;
	return 0;
}
