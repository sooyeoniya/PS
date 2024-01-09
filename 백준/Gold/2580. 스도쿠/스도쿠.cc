// 풀이 시간: 2h46m49s
// 시간 복잡도: O(9^N): N은 스도쿠 빈칸 개수(채워야 할 위치 개수)
// 공간 복잡도: O(9*10) = O(1)
// 참고 자료: https://yabmoons.tistory.com/129
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int grid[9][9];
bool row[9][10] = { false, };
bool col[9][10] = { false, };
bool square[9][10] = { false, };
//  [9]: 0~8까지 각 행/열/사각형
// [10]: 1~9까지 퍼즐에 들어갈 숫자

void dfs(int num) {
    int x = num / 9,  y = num % 9; // x:행, y:열
    if (num == 81) { // 전부 탐색이 끝나면 재귀 종료
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j)
                cout << grid[i][j] << " ";
            cout << "\n";
        }
        exit(0);
    }

    // 해당 위치 값이 0: 숫자를 채울 부분
    if (grid[x][y] == 0) {
        for (int i = 1; i <= 9; ++i) {
            if (row[x][i] == false && col[y][i] == false && square[x / 3 * 3 + y / 3][i] == false) {
                // 아래는 해당 값을 삽입하고, 값이 삽입되었다는 뜻으로 true 설정
                row[x][i] = col[y][i] = square[x / 3 * 3 + y / 3][i] = true;
                grid[x][y] = i;
                dfs(num + 1); // 재귀 함수로 다음 위치 탐색
                // 아래는 원상복귀 코드
                row[x][i] = col[y][i] = square[x / 3 * 3 + y / 3][i] = false;
                grid[x][y] = 0;
            }
        }
    }
    else dfs(num + 1); // 0이 아닐 경우 다음 위치 탐색
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // 스도쿠 전체 초기 배열
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) { // 0이 아닐 경우
                row[i][grid[i][j]] = true;
                col[j][grid[i][j]] = true;
                square[i / 3 * 3 + j / 3][grid[i][j]] = true;
            }
        }
    }
    dfs(0); // 가장 첫 번째 인덱스부터 시작
    return 0;
}