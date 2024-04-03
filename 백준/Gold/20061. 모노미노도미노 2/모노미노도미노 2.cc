// 풀이 시간: 56m24s43(문제 분석 및 정리) + 2h26m07s88(코드 작성) + 6m22s38(반례 수정)
// 시간 복잡도: 
// 공간 복잡도: 
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int N, score = 0, cnt = 0;
vector<tuple<int, int, int>> v;
bool blue[4][6] = { false, }; // 행(4) x 열(6)
bool green[6][4] = { false, }; // 행(6) x 열(4)

void tile() {
    for (int i = 5; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if (blue[j][i]) cnt++;
            if (green[i][j]) cnt++;
        }
    }
}

void move() {
    int cntB = 0, cntG = 0; // 블록이 있는 행 또는 열 개수 카운트
    for (int i = 0; i < 2; ++i) {
        if (green[i][0] || green[i][1] || green[i][2] || green[i][3]) cntG++;
        if (blue[0][i] || blue[1][i] || blue[2][i] || blue[3][i]) cntB++;
    }
    
    // 이동
    if (cntG == 1)
        for (int i = 0; i < 4; ++i)
            for (int j = 5; j > 0; --j)
                green[j][i] = green[j - 1][i];
    if (cntG == 2)
        for (int i = 0; i < 4; ++i)
            for (int j = 5; j > 1; --j)
                green[j][i] = green[j - 2][i];
    if (cntB == 1)
        for (int i = 0; i < 4; ++i)
            for (int j = 5; j > 0; --j)
                blue[i][j] = blue[i][j - 1];
    if (cntB == 2)
        for (int i = 0; i < 4; ++i)
            for (int j = 5; j > 1; --j)
                blue[i][j] = blue[i][j - 2];
    
    // 추가: 0,1번째 라인 false로 초기화
    for (int i = 0; i < 2; ++i) {
        green[i][0] = green[i][1] = green[i][2] = green[i][3] = false;
        blue[0][i] = blue[1][i] = blue[2][i] = blue[3][i] = false;
    }
}

void remove() {
    bool isLineB, isLineG;
    do {
        isLineB = false;
        for (int i = 5; i > 1; --i) {
            if (blue[0][i] && blue[1][i] && blue[2][i] && blue[3][i]) {
                for (int j = 0; j < 4; ++j) {
                    for (int k = i; k > 0; --k)
                        blue[j][k] = blue[j][k - 1];
                    blue[j][0] = false; // 추가: 0번째 라인 false로 초기화
                }
                score++;
                isLineB = true;
            }
        }
    } while (isLineB);
    do {
        isLineG = false;
        for (int i = 5; i > 1; --i) {
            if (green[i][0] && green[i][1] && green[i][2] && green[i][3]) {
                for (int j = 0; j < 4; ++j) {
                    for (int k = i; k > 0; --k)
                        green[k][j] = green[k - 1][j];
                    green[0][j] = false; // 추가: 0번째 라인 false로 초기화
                }
                score++;
                isLineG = true;
            }
        }
    } while (isLineG);
}

void put(int i) {
    int BX, BY, BX2, BY2, GX, GY, GX2, GY2;
    if (get<0>(v[i]) == 1) { // 1x1
        BX = get<1>(v[i]), BY = 1; // blue 처음 위치
        while (BY + 1 < 6 && !blue[BX][BY + 1]) BY++; // 블록이 있거나 벽을 만날 때까지 열++
        blue[BX][BY] = true;
        GX = 1, GY = get<2>(v[i]); // green 처음 위치
        while (GX + 1 < 6 && !green[GX + 1][GY]) GX++; // 블록이 있거나 벽을 만날 때까지 행++
        green[GX][GY] = true;
    }
    else if (get<0>(v[i]) == 2) { // 1x2
        BX = get<1>(v[i]), BY = 1;
        while (BY + 1 < 6 && !blue[BX][BY + 1]) BY++;
        blue[BX][BY] = blue[BX][BY - 1] = true;
        
        GX = 1, GY = get<2>(v[i]), GX2 = 1, GY2 = get<2>(v[i]) + 1;
        while (GX + 1 < 6 && !green[GX + 1][GY]) GX++;
        while (GX2 + 1 < 6 && !green[GX2 + 1][GY2]) GX2++;
        // 더 작은 행의 위치로 이동
        if (GX < GX2) green[GX][GY] = green[GX][GY2] = true;
        else green[GX2][GY] = green[GX2][GY2] = true;
    }
    else { // 2x1
        BX = get<1>(v[i]), BY = 1, BX2 = get<1>(v[i]) + 1, BY2 = 1;
        while (BY + 1 < 6 && !blue[BX][BY + 1]) BY++;
        while (BY2 + 1 < 6 && !blue[BX2][BY2 + 1]) BY2++;
        if (BY < BY2) blue[BX][BY] = blue[BX2][BY] = true;
        else blue[BX][BY2] = blue[BX2][BY2] = true;
        
        GX = 1, GY = get<2>(v[i]);
        while (GX + 1 < 6 && !green[GX + 1][GY]) GX++;
        green[GX][GY] = green[GX - 1][GY] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        v.push_back({t, x, y});
    }
    for(int i = 0; i < N; ++i) {
        put(i); // 블록 두기
        remove(); // 행열 삭제 후 내려주기
        move(); // 0,1번 위치 블록들 있을 경우 내려주기
    }
    tile(); // 초록색 보드와 파란색 보드의 블록 개수 세기
    cout << score << "\n" << cnt;
    return 0;
}