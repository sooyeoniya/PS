// 풀이 시간: 1h40m40s42
// 참고 자료: https://algosu.tistory.com/31
#include <iostream>
#define MAX 100
using namespace std;
int X, arr[MAX][MAX];
pair<int, int> start;

int move(int r, int c) {
    while (1) {
        if (r == 0) return c;
        if (c - 1 >= 0 && arr[r][c - 1]) {
            while (1) {
                if (c - 1 < 0 || !arr[r][c - 1]) break;
                c--;
            }
        }
        else if (c + 1 < MAX && arr[r][c + 1]) {
            while (1) {
                if (c + 1 >= MAX || !arr[r][c + 1]) break;
                c++;
            }
        }
        r--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 10;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int num; cin >> num;
        for (int i = 0; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                cin >> arr[i][j];
                if (arr[i][j] == 2) {
                    start.first = i;
                    start.second = j;
                }
            }
        }
        X = move(start.first, start.second);
        cout << "#" << num << " " << X << "\n";
	}
    return 0;
}
