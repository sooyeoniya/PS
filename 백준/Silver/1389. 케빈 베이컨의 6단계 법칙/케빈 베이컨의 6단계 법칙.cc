// 풀이 시간: 50m38s49(dfs 시간초과) + 19m19s20(플로이드워셜)
// 시간 복잡도: O(N^3)
// 공간 복잡도: O(N^2)

// <풀이 과정>
// dfs 깊이 우선 탐색 -> 시간 초과
// 다른 방법: bfs 너비 우선 탐색, 플로이드 워셜
// 참고: https://yabmoons.tistory.com/32
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<vector<int>> arr;

void floydwarshall() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (arr[i][k] < 1e9 && arr[k][j] < 1e9) // 둘 다 무한대가 아닌 경우에만 갱신
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

int findPerson() {
    int res = 1e9;
    int per = 1;
    for (int i = 1; i <= N; ++i) {
        int temp = 0;
        for (int j = 1; j <= N; ++j)
            temp += arr[i][j];
        if (res > temp) { // 더 작은 케빈 베이컨 수를 가진 사람으로 갱신
            res = temp;
            per = i;
        }
    }
    return per;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr = vector<vector<int>>(N + 1, vector<int>(N + 1, 1e9));
    for (int i = 1; i <= N; ++i) arr[i][i] = 0; // 자기 자신 0
    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        arr[x][y] = arr[y][x] = 1; // 친구 사이 1
    }
    floydwarshall();
    int ans = findPerson();
    cout << ans; // 케빈 베이컨 수가 가장 적고, 번호가 가장 빠른 사람 출력
    return 0;
}