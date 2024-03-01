#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, ans = 1e9, cnt = 0;
bool visited[100001] = {false, };

void bfs() {
    queue<pair<int, int>> q;
    q.push({N, 0});
    bool check = false; // while 문 안에 넣을 경우 매번 초기화되므로 밖으로 뺌

    while (!q.empty()) {
        int curX = q.front().first;
        int time = q.front().second;
        visited[curX] = true; // 큐에서 위치를 빼낸 후에 visited 배열 업데이트 되도록 수정
        q.pop();

        if (curX == K) {
            if(!check) { // 맨 처음 가장 빠른 시간일 경우에만 저장
               ans = min(ans, time);
               check = true;
            }
            if (ans == time) cnt++; // 맨 처음 저장한 값과 동일할 경우에만 cnt++
            continue; // 계속 큐 반복
        }

        if (curX - 1 >= 0 && !visited[curX - 1])
            q.push({curX - 1, time + 1});
        if (curX + 1 <= 100000 && !visited[curX + 1])
            q.push({curX + 1, time + 1});
        if (curX * 2 <= 100000 && !visited[curX * 2])
            q.push({curX * 2, time + 1});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    bfs();
    cout << ans << "\n" << cnt;
    return 0;
}
