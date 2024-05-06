#include <iostream>
#include <vector>
using namespace std;
int N, M, a, b;
bool ans = false;
vector<vector<int>> arr;
vector<bool> visited;

void dfs(int n, int cnt) {
    if (cnt == 4) { ans = true; return; }
    visited[n] = true;
    for (int i = 0; i < arr[n].size(); ++i)
        if (!visited[arr[n][i]]) dfs(arr[n][i], cnt + 1);
    visited[n] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr = vector<vector<int>>(N);
    visited = vector<bool>(N, false);
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (int i = 0; i < N; ++i) {
        dfs(i, 0);
        if (ans) break;
    }
    cout << ans;
    return 0;
}