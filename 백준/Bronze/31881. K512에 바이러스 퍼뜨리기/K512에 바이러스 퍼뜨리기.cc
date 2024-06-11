// 풀이 시간: 13m12s29
// 시간 복잡도: O(Q)
// 공간 복잡도: O(N)

#include <iostream>
#include <vector>
using namespace std;
int N, Q, a, b;
vector<bool> arr;
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    arr = vector<bool>(N + 1, false);
    cnt = N;

    for (int i = 0; i < Q; ++i) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            if (!arr[b]) {
                arr[b] = true;
                cnt--;
            }
        } else if (a == 2) {
            cin >> b;
            if (arr[b]) {
                arr[b] = false;
                cnt++;
            }
        } else if (a == 3) {
            cout << cnt << "\n";
        }
    }
    return 0;
}