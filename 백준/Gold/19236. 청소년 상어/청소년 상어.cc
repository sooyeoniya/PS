#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ans = 0;
vector<vector<int>> arr(4, vector<int>(4, 0)); // 물고기 번호 위치
int dir[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

// 물고기 구조체 { 위치(x, y), 방향, 생존 여부 }
struct Fish {
    int x, y, dir;
    bool live;
};

// 상어 구조체 { 위치(x, y), 방향 }
struct Shark {
    int x, y, dir;
};

Fish fish[17]; // 물고기 구조체 배열 (총 16마리)
Shark shark; // 상어 구조체

// 물고기 이동
void fishMove() {
    for (int i = 1; i < 17; ++i) {
        if (!fish[i].live) continue; // 죽은 물고기는 스킵
        int d = fish[i].dir, nX, nY, nextFishNum;
        do { 
            // 다음 위치
            nX = fish[i].x + dir[d][0];
            nY = fish[i].y + dir[d][1];

            // 공간을 벗어나거나, 상어가 있는 위치일 경우 45도 반시계 회전 후 다시 탐색
            if (nX < 0 || nX >= 4 || nY < 0 || nY >= 4 || (shark.x == nX && shark.y == nY)) d = (d + 1) % 8;
            else { 
                // 교환 가능한 위치인 경우 물고기 위치 교환
                /* 죽은 물고기더라도 그 물고기의 구조체 위치는 계속 이동(다른 물고기와의 교환을 위해 필요)
                죽은 물고기는 live = false, arr[i][j]=0으로 변경됨 (상어가 arr를 통해 먹을 것이기 때문에 arr을 0으로 만들어 주어야 함) */
                nextFishNum = arr[nX][nY];
                fish[nextFishNum].x = fish[i].x;
                fish[nextFishNum].y = fish[i].y;
                arr[fish[i].x][fish[i].y] = nextFishNum; // 추가
                fish[i].x = nX;
                fish[i].y = nY;
                fish[i].dir = d; // 현재 물고기 방향도 갱신
                arr[nX][nY] = i; // 추가
                break; 
            }
        } while (d != fish[i].dir); // 다시 제자리 방향으로 돌아왔을 경우 종료
    }
}

void dfs(int cnt) {
    vector<vector<int>> tempArr = arr; // 배열 임시 저장
    Fish tempFish[17]; // 추가
    copy(begin(fish), end(fish), begin(tempFish)); // 추가
    int tempDir = shark.dir; // 상어 방향 변동 없음

    fishMove(); // 물고기 이동

    for (int i = 1; i < 4; ++i) {
        // 상어가 탐색할 다음 위치
        int nX = shark.x + dir[tempDir][0] * i;
        int nY = shark.y + dir[tempDir][1] * i;

        if (nX < 0 || nX >= 4 || nY < 0 || nY >= 4) continue; // 범위 이탈 제외
        int nextFishNum = arr[nX][nY]; // 다음 물고기 번호 임시 저장
        if (nextFishNum == 0 || !fish[nextFishNum].live) continue; // 죽은 물고기 제외

        // 상어 이동 및 해당 위치 물고기 먹음
        shark = { nX, nY, fish[nextFishNum].dir };
        arr[nX][nY] = 0;
        fish[nextFishNum].live = false;

        dfs(cnt + nextFishNum); // 다음 탐색 진행

        // 백트래킹
        fish[nextFishNum].live = true;
        arr[nX][nY] = nextFishNum;
        shark.x -= dir[tempDir][0] * i;
        shark.y -= dir[tempDir][1] * i;
        shark.dir = tempDir; // 수정
    }

    ans = max(cnt, ans); // 상어가 먹은 물고기 최댓값 갱신
    copy(begin(tempFish), end(tempFish), begin(fish)); // 추가
    arr = tempArr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a >> b;
            arr[i][j] = a;
            if (i == 0 && j == 0) {
                fish[a] = { i, j, b - 1, false }; // 0, 0 위치 물고기 정보
                ans += a; // 0, 0 위치의 물고기 번호 삽입 (상어가 미리 먹고 시작)
                shark = { i, j, b - 1 }; // 상어 구조체 정보 저장
            }
            else fish[a] = { i, j, b - 1, true };
        }
    }
    dfs(ans); // 현재까지 먹은 물고기 수
    cout << ans;
    return 0;
}