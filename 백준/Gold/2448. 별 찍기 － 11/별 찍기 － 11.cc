// 풀이 시간: 57m13s61(고민) + 28m16s94(참고)
// 시간 복잡도: O(NlogN)
// 공간 복잡도: O(N^2)
#include <iostream>
using namespace std;
int N;
char arr[3072][6144]; // 행(N), 열(2*N-1)

void star(int n, int x, int y) {
    if (n == 3) { // 가장 작은 삼각형 별 찍기
        arr[y][x] = '*';
        arr[y + 1][x - 1] = '*';
        arr[y + 1][x + 1] = '*';
        arr[y + 2][x - 2] = '*';
        arr[y + 2][x - 1] = '*';
        arr[y + 2][x] = '*';
        arr[y + 2][x + 1] = '*';
        arr[y + 2][x + 2] = '*';
        return;
    }
    // n이 3이 아닌 경우, 작은 삼각형 3개로 쪼개어 재귀 호출
    star(n / 2, x, y);
    star(n / 2, x - (n / 2), y + (n / 2));
    star(n / 2, x + (n / 2), y + (n / 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) // 배열 초기화
        for (int j = 0; j < 2 * N; ++j)
            arr[i][j] = ' '; // 공백

    star(N, N - 1, 0); // 삼각형 꼭대기 (x, y)좌표

    for (int i = 0; i < N; ++i) { // 배열 출력
        for (int j = 0; j < 2 * N; ++j)
            cout << arr[i][j];
        cout << '\n';
    }

    return 0;
}