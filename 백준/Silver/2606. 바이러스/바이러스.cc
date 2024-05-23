// 풀이 시간: 11m42s82(bfs) + 1m22s69(dfs)
// 시간 복잡도: O(N)
// 공간 복잡도: O(NM) // 최대 시간복잡도

// <풀이 과정>
// 연결리스트로 간선 저장
// 1번 컴퓨터부터 큐에 넣고 1번 컴퓨터와 연결된 다른 컴퓨터를 연결리스트에서 찾아서 이동
// 오답 -> 양방향 간선 연결
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, ans = 0;
vector<vector<int>> arr;
vector<int> visited;

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < arr[cur].size(); ++i) {
            int next = arr[cur][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                ans++;
            }
        }
    }
}

void dfs(int num) {
    visited[num] = true;
    for (int i = 0; i < arr[num].size(); ++i) {
        int next = arr[num][i];
        if (!visited[next]) {
            visited[next] = true;
            ans++;
            dfs(next);
        }
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
        int a, b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a); // 양방향 연결
    }
    // bfs();
    dfs(1);
    cout << ans;
    return 0;
}
