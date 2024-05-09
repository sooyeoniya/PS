// MST, Union-Find
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, ans = 0;
int parent[1001] = { 0, };
char univ[1001] = { "", };
vector<pair<int, pair<int, int>>> arr;

// 부모노드 가져오기
int getParent(int node) {
    if (parent[node] == node) return node;
    else return getParent(parent[node]);
}

// 노드 연결, 더 작은 부모노드로 변경
void unionParent(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 < node2) parent[node2] = node1;
    else parent[node1] = node2;
}

// 사이클인지 판단
bool isCycle(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 == node2) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) { parent[i] = i; cin >> univ[i]; } // 부모 노드 초기화
    for (int i = 0; i < M; ++i) {
        int u, v, d; cin >> u >> v >> d;
        if (univ[u] != univ[v]) arr.push_back({d, {u, v}}); // 남초-여초일 때만 연결
    }
    sort(arr.begin(), arr.end()); // 최소 비용부터 더해주기 위해 정렬
    int cnt = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (!isCycle(arr[i].second.first, arr[i].second.second)) {
            ans += arr[i].first; // 비용 추가
            unionParent(arr[i].second.first, arr[i].second.second); // 부모 합침
            if (++cnt == N - 1) {
                cout << ans;
                return 0;
            }
        }
    }
    cout << "-1";
    return 0;
}