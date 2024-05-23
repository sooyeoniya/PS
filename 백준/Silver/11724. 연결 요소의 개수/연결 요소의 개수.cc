// 풀이 시간: 5m36s21
// 시간 복잡도: O(NM)
// 공간 복잡도: O(NM)

// <풀이 과정>
// dfs - N개를 돌면서 방문하지 않은 노드만 dfs 호출 후 ans++
// 자연스럽게 연결된 부분은 다 dfs 내부에서 visited = true 됨
// 따라서 연결이 끊긴 노드들의 그룹 개수를 셀 수 있음

#include <iostream>
#include <vector>
using namespace std;
int N, M, ans = 0; 
vector<vector<int>> arr;
vector<int> visited;

void dfs(int idx) {
    visited[idx] = true;
    for (int i = 0; i < arr[idx].size(); ++i) {
        int next = arr[idx][i];
        if (!visited[next]) dfs(next);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr = vector<vector<int>>(N + 1);
    visited = vector<int>(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans;
    return 0;
}