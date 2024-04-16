// 풀이 시간: 18m27s34 + 9m36s97
// 시간 복잡도: O(log maxL)
// 공간 복잡도: O(K)
// 참고 자료: https://yongmemo.tistory.com/21
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
unsigned int N, K, temp, ans = 0, maxL = 0;
unsigned int len[10000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> K >> N;
    for (int i = 0; i < K; ++i) {
        cin >> len[i];
        maxL = max(maxL, len[i]);
    }
    unsigned int left = 1, right = maxL, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        unsigned int now = 0; // 몫의 합을 저장하는 변수
        for (int i = 0; i < K; ++i) now += len[i] / mid;
        if (now >= N) {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else right = mid - 1;
    }
    cout << ans;
    return 0;
}