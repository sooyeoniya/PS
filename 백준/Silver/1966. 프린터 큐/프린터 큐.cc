// 풀이 시간: 20m31s40
// 시간 복잡도: O(N^2logN)
// 공간 복잡도: O(N)
#include <iostream>
#include <queue>
using namespace std;
int T, N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int cnt = 0;
        cin >> N >> M;
        queue<pair<int, int>> q; // idx, 중요도
        priority_queue<int> pq; // 중요도 큰 순
        for (int j = 0; j < N; ++j) {
            int import; cin >> import;
            q.push({j, import});
            pq.push(import);
        }

        while (!q.empty()) {
            int curIdx = q.front().first;
            int curImport = q.front().second;
            q.pop();

            if (pq.top() == curImport) {
                pq.pop();
                cnt++;
                if (curIdx == M) {
                    cout << cnt << "\n";
                    break;
                }
            }
            else q.push({curIdx, curImport});
        }
    }
    return 0;
}