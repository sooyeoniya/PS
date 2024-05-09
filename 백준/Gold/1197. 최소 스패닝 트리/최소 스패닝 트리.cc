#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans = 0;
vector<int> parent;
vector<pair<int, pair<int, int>>> arr;

int getParent(int node) {
    if (parent[node] == node) return node;
    else return getParent(parent[node]);
}

void unionParent(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 < node2) parent[node2] = node1;
    else parent[node1] = node2;
}

bool isCycle(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 == node2) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int v, e; cin >> v >> e;
    parent = vector<int>(v + 1, 0);
    for (int i = 1; i <= v; ++i) parent[i] = i;
    for (int i = 0; i < e; ++i) {
        int a, b, c; cin >> a >> b >> c;
        arr.push_back({c, {a, b}});
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); ++i) {
        if (!isCycle(arr[i].second.first, arr[i].second.second)) {
            ans += arr[i].first;
            unionParent(arr[i].second.first, arr[i].second.second);
        }
    }
    cout << ans;
    return 0;
}