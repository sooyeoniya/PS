#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, ans = 0;
vector<vector<int>> arr;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우

void move(int pos) {
    if (pos == 0) { // 상
        for (int j = 0; j < N; ++j) {
            int idx = 0;
            queue<int> q;
            for (int i = 0; i < N; ++i) {
                if (arr[i][j] != 0) q.push(arr[i][j]); // (1)
                arr[i][j] = 0; // 해당 라인 전부 초기화
            }
            while (!q.empty()) { // 값을 모두 배치할 때까지 진행
                int value = q.front(); // 현재 값은 다음 if문을 통해 모두 처리해야 함
                q.pop();
                if (arr[idx][j] == 0) arr[idx][j] = value; // (2)
                else if (arr[idx][j] == value) { arr[idx][j] *= 2; idx++; } // (3)
                else { idx++; arr[idx][j] = value; } // (4)
            }
        }
    }
    if (pos == 1) { // 하
        for (int j = 0; j < N; ++j) {
            int idx = N - 1;
            queue<int> q;
            for (int i = N - 1; i >= 0; --i) {
                if (arr[i][j] != 0) q.push(arr[i][j]);
                arr[i][j] = 0;
            }
            while (!q.empty()) {
                int value = q.front();
                q.pop();
                if (arr[idx][j] == 0) arr[idx][j] = value;
                else if (arr[idx][j] == value) { arr[idx][j] *= 2; idx--; }
                else { idx--; arr[idx][j] = value; }
            }
        }
    }
    if (pos == 2) { // 좌
        for (int i = 0; i < N; ++i) {
            int idx = 0;
            queue<int> q;
            for (int j = 0; j < N; ++j) {
                if (arr[i][j] != 0) q.push(arr[i][j]);
                arr[i][j] = 0;
            }
            while (!q.empty()) {
                int value = q.front();
                q.pop();
                if (arr[i][idx] == 0) arr[i][idx] = value;
                else if (arr[i][idx] == value) { arr[i][idx] *= 2; idx++; }
                else { idx++; arr[i][idx] = value; }
            }
        }
    }
    if (pos == 3) { // 우
        for (int i = 0; i < N; ++i) {
            int idx = N - 1;
            queue<int> q;
            for (int j = N - 1; j >= 0; --j) {
                if (arr[i][j] != 0) q.push(arr[i][j]);
                arr[i][j] = 0;
            }
            while (!q.empty()) {
                int value = q.front();
                q.pop();
                if (arr[i][idx] == 0) arr[i][idx] = value;
                else if (arr[i][idx] == value) { arr[i][idx] *= 2; idx--; }
                else { idx--; arr[i][idx] = value; }
            }
        }
    }
}

void play(int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                ans = max(ans, arr[i][j]);
        return;
    }
    // 보드 갱신
    int temp[20][20]; // ** 수정: 매번 보드를 새로 선언해야함
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[i][j] = arr[i][j];

    for (int i = 0; i < 4; ++i) {
        move(i); // 상하좌우 순서대로
        play(cnt + 1); // 이동 횟수 증가

        // 원상복귀(백트래킹)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                arr[i][j] = temp[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    arr = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];
    play(0);
    cout << ans;
    return 0;
}