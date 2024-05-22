// 풀이 시간: 1h1m59s48
// 시간 복잡도: O(RC)
// 공간 복잡도: O(RC)

// <풀이 과정>
// 32m -> 문제 잘못 해석하고 완전 다르게 풂 (삭제)
// 20m59s70 -> 4% 반례 발생 (https://www.acmicpc.net/board/view/118223)
// 9m59s48 -> 4% 반례 오류 찾기
// 오류) check 변수를 사용하여 세 방향 중 첫 번째 가능한 경로를 찾으면 즉시 재귀 호출(dfs(nR, nC))을 하고 반환됨. 이렇게 하면 나머지 두 방향을 탐색하지 않기 때문에 경로를 놓치는 경우가 생김.
// 해결 방안) check 변수를 for문 안에 하나 더 추가하여 각각의 방향 별로 확인하는 check 변수를 두던지, 아니면 아예 check 변수를 두지 않고, 그냥 dfs 함수에서 바로 return 되도록 변경하면 됨.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int R, C, ans = 0;
vector<vector<char>> arr;
vector<vector<bool>> visited;
int dir[3] = { -1, 0, 1 }; // 오른쪽위, 오른쪽, 오른쪽아래

bool dfs(int r, int c) {
    if (c == C - 1) return true;
    visited[r][c] = true;
    for (int j = 0; j < 3; ++j) {
        int nR = r + dir[j];
        int nC = c + 1;
        if (nR < 0 || nR >= R || nC < 0 || nC >= C || visited[nR][nC] || arr[nR][nC] == 'x') continue;
        if (dfs(nR, nC)) return true; // 수정 (dfs 반환값이 true일 때 return true)
    }
    return false; // 수정 (중간에서 true로 리턴 안되면 그냥 false 리턴)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> R >> C;
    arr = vector<vector<char>>(R, vector<char>(C, '.'));
    visited = vector<vector<bool>>(R, vector<bool>(C, false));
    for (int i = 0; i < R; ++i) {
        string str; cin >> str;
        for (int j = 0; j < str.size(); ++j) {
            arr[i][j] = str[j];
        }
    }
    for (int i = 0; i < R; ++i)
        if (arr[i][1] == '.' && !visited[i][1] && dfs(i, 1)) ans++;
    cout << ans;
    return 0;
}
