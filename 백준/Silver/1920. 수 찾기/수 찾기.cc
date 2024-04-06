// 풀이 시간: 12m53s97
// 시간 복잡도: O(N+M)
// 공간 복잡도: O(N)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    int M; cin >> M;
    for (int i = 0; i < M; ++i) {
        int X; cin >> X;
        int left = 0, right = N - 1;
        bool find = false;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (X > A[mid]) left = mid + 1;
            else if (X < A[mid]) right = mid - 1;
            else if (X == A[mid]) { find = true; break; }
        }
        if (find) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}