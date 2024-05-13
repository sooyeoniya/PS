// 풀이 시간: 54m06s75
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, ans;
int gem[300000] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) cin >> gem[i];
    sort(gem, gem + M); // 정렬 필수로 해주어야 함. -> r 설정 시 맨 마지막 값(가장 큰 값)으로 설정하기 위해, 사실 그냥 위에 for 문에서 가장 큰 값을 따로 저장해서 r에 대입해줘도 됨

    int l = 1, r = gem[M - 1], m; // 질투심 값
    while (l <= r) {
        m = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            cnt += gem[i] / m; // 최대 m(질투심 개수)만큼 가져감
            if (gem[i] % m) cnt++; // 보석 나머지가 생기면 한명 더 나누어 주어야 함
        }
        if (cnt <= N) { // cnt가 N보다 작거나 같은 경우
            r = m - 1; 
            ans = m; 
        }
        else l = m + 1; 
    }
    cout << ans;
    return 0;
}
