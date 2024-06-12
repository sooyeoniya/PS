// 풀이 시간: 1h40m34s69
// 시간 복잡도: O(NlogN)
// 공간 복잡도: O(N)

#include <iostream>
using namespace std;
int N, arr[7][99]; // arr[day][N];

void match(int st, int ed, int team, int day) {
    if (day == 7) return; // 7일 되면 종료
    int mid = (st + ed) / 2;
    for (int i = st; i <= ed; ++i) // mid 기준 분할
        arr[day][i] = i <= mid ? team : !team;
    match(st, mid, !team, day + 1);
    match(mid + 1, ed, team, day + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    match(0, N - 1, 0, 0);
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < N; ++j) {
            // arr 값에 따라 두 팀으로 분할
            if (arr[i][j]) cout << 'A'; 
            else cout << 'B';
        }
        cout << "\n";
    }
    return 0;
}