#include <iostream>
#include <vector>
using namespace std;
int N, M, ans = 0;
vector<vector<int>> arr;
// dir[n][i][j]: n번째 테트로미노, i번째 줄, j번째 칸
int dir[19][3][2] = {
	// ㄹ자
	{{1, 0}, {1, 1}, {2, 1}}, 
	{{0, 1}, {-1, 1}, {-1, 2}},
	{{1, 0}, {1, -1}, {2, -1}},
	{{0, 1}, {1, 1}, {1, 2}},
	// ㄴ자
	{{1, 0}, {2, 0}, {2, 1}},
	{{0, 1}, {0, 2}, {-1, 2}},
	{{-1, 0}, {-1, 1}, {-1, 2}},
	{{0, 1}, {1, 1}, {2, 1}},
	{{1, 0}, {2, 0}, {2, -1}},
	{{0, 1}, {0, 2}, {1, 2}},
	{{1, 0}, {1, 1}, {1, 2}},
	{{0, -1}, {1, -1}, {2, -1}},
	// ㅜ자
	{{0, 1}, {0, 2}, {1, 1}},
	{{1, 0}, {2, 0}, {1, 1}},
	{{1, -1}, {1, 0}, {1, 1}},
	{{-1, 1}, {0, 1}, {1, 1}},
	// ㅣ자
	{{0, 1}, {0, 2}, {0, 3}},
	{{1, 0}, {2, 0}, {3, 0}},
	// ㅁ자
	{{0, 1}, {1, 0}, {1, 1}}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	arr = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];
	
	for (int i = 0; i < N; ++i) { // 행
		for (int j = 0; j < M; ++j) { // 열
			for (int k = 0; k < 19; ++k) { // 테트로미노 종류
				int sum = arr[i][j]; // 합계, 초깃값: 현재 위치의 값
				for (int l = 0; l < 3; ++l) { // 정사각형 4개 좌표
					int nextX = i + dir[k][l][0]; // 다음 행 좌표
					int nextY = j + dir[k][l][1]; // 다음 열 좌표

					// 배열 범위 초과할 경우 해당 테트로미노는 유효하지 않으므로 다음 테트로미노 탐색
					if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) break;
					// 다음 위치의 값 누적 합
					sum += arr[nextX][nextY];
				}
				ans = max(ans, sum); // 최댓값 갱신
			}
		}
	}
	cout << ans;
	return 0;
}