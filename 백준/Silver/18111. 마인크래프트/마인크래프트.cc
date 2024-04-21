// 풀이 시간: 16m12s92
// 시간 복잡도: O(hNM)
// 공간 복잡도: O(NM)
#include <iostream>
#include <vector>
using namespace std;
int N, M, B, mintime = 1e9, maxH = -1;
vector<vector<int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> B;
    arr = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> arr[i][j];
    for (int h = 0; h <= 256; ++h) {
        int inven = 0;
        int remove = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int curH = arr[i][j] - h;
                if (curH < 0) inven -= curH;
                else remove += curH;
            }
        }
        if (remove + B >= inven) {
            int ttime = 2 * remove + inven;
            if (mintime >= ttime) {
                mintime = ttime;
                maxH = h;
            }
        }
    }
    cout << mintime << " " << maxH;
    return 0;
}