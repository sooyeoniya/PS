// 풀이 시간: 30m16s42(초기 코드) + 31m52s87(오류 수정)
// 시간 복잡도: O((N−1)^N)
// 공간 복잡도: O(N)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, ans = 0;
vector<int> S, W; // 내구도, 무게

void dfs(int egg) {
    if (egg > N) { // 가장 오른쪽 계란(N)까지 완전히 끝난 경우
        int cnt = 0;
        for (int i = 1; i <= N; ++i) // 깨진 계란 카운트
            if (S[i] <= 0) cnt++;
        ans = max(ans, cnt); // 최댓값으로 갱신
        return; 
    }

    if (S[egg] <= 0) dfs(egg + 1); // 이미 깨져있으면 다음으로 넘김
    else {
        bool check = false;
        for (int i = 1; i <= N; ++i) { // 이 중 하나를 침
            if (egg == i || S[i] <= 0) continue; // 자기 자신이거나, 다른 계란이 이미 깨져있는 경우

            S[i] -= W[egg]; // i의 내구도 감소
            S[egg] -= W[i]; // egg의 내구도 감소

            check = true; // 한 번이라도 깨진 계란이 있으면 다음 탐색
            dfs(egg + 1); // 한 칸 오른쪽 계란 호출
            
            // 백트래킹
            S[i] += W[egg];
            S[egg] += W[i];
        }

        // 모든 계란을 탐색했는데, 본인을 제외한 나머지가 다 깨져있는 경우
        if (!check) dfs(N + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    S = W = vector<int>(N + 1, 0);
    for (int i = 1; i <= N; ++i) cin >> S[i] >> W[i];
    dfs(1); // 손에 든 계란
    cout << ans;
    return 0;
}

// [오류1]
// 왼쪽 계란을 들어서 무조건 오른쪽에 있는 계란들만 쳐야하는 줄 알았음
// 그래서 계속 답이 안나옴
// "i = egg + 1" -> 이게 아니라 "i = 1" 여야 함
// 그리고 자기 자신인 경우 continue 해주기

// [오류2]
// "dfs(i)"가 아니라 "dfs(egg + 1)"을 호출해야 함
// "한 칸 오른쪽 계란"을 다시 손에 들어야 함

// [오류3]
// "예제 입력 7"의 출력값이 다르게 나옴
// dfs에서 가장 오른쪽 계란까지 계산 끝나고 인자로 "N + 1"을 받았을 때 종료해야 함
// 내 기존 코드에서는 dfs() 인자로 "N"을 받았을 때 가장 오른쪽 계란(N)을 탐색하지 않고 종료해버림
// 따라서, "if (egg == N)"이 아니라 "if (egg > N)"이어야 함

// [오류4]
// 참고: https://prefer2.tistory.com/entry/백준-16987번-계란으로-계란치기-c
// "오류3" 수정한 뒤 발생한 오류
// "예제 입력 2"의 출력값이 갑자기 0으로 나옴
// 이 경우에, 앞서 계산되는 1번 계란과 2번 계란에서 이미 둘 다 (-)가 되어버리기 때문에
// 3번 계란을 탐색할 때 for문 내부의 조건문에서 계속 continue 되어 결국 dfs가 끝까지 돌지 못하고 빠져나옴
// 그렇게 되면 dfs 초반의 if 문을 돌지 못하기 때문에 ans값이 갱신되지 않아 결국 0이 나오는 것임
// 따라서 check 변수를 추가하여 이미 다 깨져있는 경우에는 dfs문을 강제로 돌려줌
// 이때 (N + 1)을 넘겨주어 깨진 계란 수가 갱신이 되도록 함