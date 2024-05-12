#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, Q;
long long tAns = 0, cAns = 0; // 타입 변경
int parent[200001] = { 0, };
vector<pair<pair<long long, long long>, pair<int, int>>> arr; // 타입 변경

// 부모노드 찾기
int getParent(int node) {
    if (node == parent[node]) return node;
    return parent[node] = getParent(parent[node]); // 수정(시간 초과 원인)
}

// 부모 합치기
void unionParent(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 < node2) parent[node2] = node1;
    else parent[node1] = node2;
}

// 사이클 판단
bool isCycle(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 == node2) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) parent[i] = i; // 부모 입력

    for (int i = 0; i < Q; ++i) { // 노선에 대한 시간 및 비용 입력
        int from, to;
        long long cost, time;
        cin >> from >> to >> cost >> time;
        arr.push_back({{cost, time}, {from, to}});
    }
    
    sort(arr.begin(), arr.end()); // 정렬

    for (int i = 0; i < arr.size(); ++i) {
        if (!isCycle(arr[i].second.first, arr[i].second.second)) {
            unionParent(arr[i].second.first, arr[i].second.second);
            cAns += arr[i].first.first;
            tAns = max(tAns, arr[i].first.second);
        }
    }

    for (int i = 2; i <= N; ++i) { // 나머지 노드들 탐색하여 가희와 연결되었는지 확인
        if (getParent(i) != 1) { // 가희와 연결되지 않은 경우
            cout << "-1";
            return 0;
        }
    }
    cout << tAns << " " << cAns;
    return 0;
}
