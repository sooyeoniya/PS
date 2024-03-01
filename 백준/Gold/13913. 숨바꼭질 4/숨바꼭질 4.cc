#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
bool visited[100001] = {false, };
int path[100001];

void bfs() {
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;

    while (!q.empty()) {
        int curX = q.front().first;
        int time = q.front().second;
        q.pop();

        if (curX == K) {
            cout << time << "\n";
            vector<int> v;
            while (curX != N) {
                v.push_back(curX);
                curX = path[curX];
            }
            v.push_back(N);
            reverse(v.begin(), v.end());
            for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
            return;
        }

        if (curX - 1 >= 0 && !visited[curX - 1]) {
            q.push({curX - 1, time + 1});
            visited[curX - 1] = true;
            path[curX - 1] = curX;
        }
        if (curX + 1 <= 100000 && !visited[curX + 1]) {
            q.push({curX + 1, time + 1});
            visited[curX + 1] = true;
            path[curX + 1] = curX;
        }
        if (curX * 2 <= 100000 && !visited[curX * 2]) {
            q.push({curX * 2, time + 1});
            visited[curX * 2] = true;
            path[curX * 2] = curX;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    bfs();
    return 0;
}
