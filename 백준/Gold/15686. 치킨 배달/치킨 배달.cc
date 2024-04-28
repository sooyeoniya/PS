#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool isSelected[13] = { false, };
int N, M, ans = 1e9, arr[50][50] = { 0, };
vector<pair<int, int>> house, chicken, V;

int calDis() {
    int sum = 0;
    for (int i = 0; i < house.size(); ++i) {
        int x = house[i].first;
        int y = house[i].second;
        int d = 1e9;
        for (int j = 0; j < V.size(); ++j) {
            int xx = V[j].first;
            int yy = V[j].second;
            int dd = abs(xx - x) + abs(yy - y);
            d = min(dd, d);
        }
        sum += d;
    }
    return sum;
}

void selectChicken(int idx, int cnt) {
    if (cnt == M) { ans = min(ans, calDis()); return; }
    for (int i = idx; i < chicken.size(); ++i) {
        if (isSelected[i]) continue;
        isSelected[i] = true;
        V.push_back(chicken[i]);
        selectChicken(i, cnt + 1);
        isSelected[i] = false;
        V.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) house.push_back({i, j});
            if (arr[i][j] == 2) chicken.push_back({i, j});
        }
    }
    selectChicken(0, 0);
    cout << ans;
    return 0;
}