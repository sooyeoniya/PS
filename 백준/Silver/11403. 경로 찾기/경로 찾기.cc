// 풀이 시간: 6m51s13
// 시간 복잡도: O(N^3)
// 공간 복잡도: O(N^2)
// 풀이 방법: 플로이드-워셜 알고리즘

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // 입력
    int arr[101][101] = { 0, };
    int N; cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];

    // 플로이드 워셜
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (arr[i][k] && arr[k][j])
                    arr[i][j] = 1;

    // 출력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}