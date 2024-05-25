// 풀이 시간: 26m2s10
// 시간 복잡도: O(N^2 log N)
// 공간 복잡도: O(N^2)

// <풀이 과정>
// recur 재귀 함수 선언
// 초기 좌표와 배열 크기 (N)을 인자로 넘김
// 우선 배열 전체에 1과 0의 개수 각각 세기
// len * len 크기와 각각의 개수가 같다면, 해당 면적은 전부 하나의 숫자로 이루어져있는 것이므로 각 색종이 수 카운트 하고 종료
// 만약 그렇지 않다면 len이 1이 되기 전까지 재귀호출, 이때 len를 전부 1/2 하기
#include <iostream>
using namespace std;
int N, white = 0, blue = 0; // while: 0, blue: 1
int arr[129][129] = { 0, };

void recur(int x, int y, int len) {
    int w = 0, b = 0;
    for (int i = x; i < x + len; ++i) {
        for (int j = y; j < y + len; ++j) {
            if (arr[i][j] == 1) b++;
            else w++;
        }
    }
    if (w == len * len) {
        white++; return;
    }
    else if (b == len * len) { 
        blue++; return;
    }
    else if (len > 1) {
        recur(x, y, len / 2);
        recur(x + len / 2, y, len / 2);
        recur(x, y + len / 2, len / 2);
        recur(x + len / 2, y + len / 2, len / 2);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];
    recur(0, 0, N);
    cout << white << "\n" << blue;
    return 0;
}