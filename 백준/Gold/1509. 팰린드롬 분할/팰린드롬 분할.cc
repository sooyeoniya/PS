// 풀이 시간: 2h19m12s02
// 시간 복잡도: O(N^2)
// 공간 복잡도: O(N^2)
// 참고 코드
// https://hyeo-noo.tistory.com/137
// https://yabmoons.tistory.com/592
#include <iostream>
#include <string>
#define MAX 2501
#define INF 1e9
using namespace std;
string str;
int N, ans[MAX]; // ans[N]: N번째 문자열까지 탐색했을 때 팰린드롬 분할 개수의 최솟값
bool dp[MAX][MAX]; // dp[i][j]: i번째부터 j번째까지가 하나의 팰린드롬인 경우

// start부터 end까지 팰린드롬인지 확인
bool isPal(int start, int end) {
    // 1. 처음과 끝이 동일하고 
    // 2-1. 처음과 끝을 제외한 나머지 부분의 dp가 true
    // 2-2. 또는 문자열 길이가 2인 경우 true
    if (str[start] == str[end] 
    && (dp[start + 1][end - 1]
    || end - start == 1)) return true;
    return false;
}

// dp 배열 값 설정
void setDP() {
    for (int dis = 0; dis < N; ++dis) {
        for (int i = 1; i + dis <= N; ++i) {
            if (dis == 0) dp[i][i] = true; // 각각의 문자 하나하나는 모두 팰린드롬
            else if (isPal(i, i + dis)) dp[i][i + dis] = true;
        }
    }
}

// 팰린드롬 분할 개수의 최솟값 찾기
void setAns() {
    ans[0] = 0;
    for (int ed = 1; ed <= N; ++ed) {
        ans[ed] = INF;
        for (int st = 1; st <= ed; ++st) {
            if (dp[st][ed]) ans[ed] = min(ans[ed], ans[st - 1] + 1);
            // ans[st - 1] + 1: 이전까지의 문자열의 최소 팰린드롬 분할 수 + 현재 문자 1
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> str;
    N = str.size();
    str = " " + str; // 문자열 인덱스 1부터 시작하도록 맞춰줌
    setDP(); setAns();
    cout << ans[N];
    return 0;
}
