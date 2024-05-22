// 풀이 시간: 
// 시간 복잡도: 
// 공간 복잡도: 

// <풀이 과정>
// 32m -> 문제 잘못 해석하고 완전 다르게 풂
// 20m59s70 -> 4% 반례
// 오류 찾기 -> 

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
        if (dfs(nR, nC)) return true;
    }
    return false;
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