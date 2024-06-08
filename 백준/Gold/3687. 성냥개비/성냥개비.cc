// 풀이 시간: 23m08s02(고민) + 53m42s02(풀이 참고)
// 시간 복잡도: O(T*N)
// 공간 복잡도: O(1)
// 참고: https://kd-codebook.tistory.com/64
#include <iostream>
#include <algorithm>
#define MAX 101 // N의 최대 크기
using namespace std;
int num[9] = { 0, 0, 1, 7, 4, 2, 0, 8, 10 }; // 성냥개비 개수별 만들 수 있는 최소 수
long long dp[MAX]; // 최소 수 저장 dp

void min_cal() { // dp 계산
    for (int i = 1; i < 9; ++i) dp[i] = num[i]; // 1~8개로 만들 수 있는 최소 수
    dp[6] = 6;
    // 처음 성냥개비 6개로 만들 수 있는 최소 수는 6
    // 그 이후로는 숫자 0 가능 (num[6] = 0)

    // 성냥개비가 9~100개일 때 만들 수 있는 최소 수 계산
    for (int i = 9; i < 101; ++i) {
        // 성냥개비가 2~7개까지일 때의 dp 값을 이용하여 계산
        // num에 저장된 8의 최소 수는 10이지만, 직접적으로 사용되지는 않음. 단지 맨 위 for 문에서 dp[8] 값을 삽입할 때만 사용됨 (그니까 왜지?)
        dp[i] = dp[i - 2] * 10 + num[2];
        for (int j = 3; j < 8; ++j)
            dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);
    }
}

void max_cal(int N) { // 가장 큰 수 출력
    // 가장 "적은" 개수로 최소 수와 최대 수 추출
    // 그래야 자릿수를 더 늘릴 수 있음

    // 2개로 만들 수 있는 최소 수 1
    // 3개로 만들 수 있는 최대 수 7
    while (N > 0) {
        if (N % 2 != 0) { // 홀수
            cout << 7;
            N -= 3;
        }
        else { // 짝수
            cout << 1;
            N -= 2;
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    min_cal();
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        int N; cin >> N;
        cout << dp[N] << " "; // 가장 작은 수 출력
        max_cal(N);
    }
    return 0;
}