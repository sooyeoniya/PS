// 풀이 시간: 31m23s38
// 시간 복잡도: O(T*N^3)
// 공간 복잡도: O(T*N)

// <풀이 과정>
// 참고 자료: https://lbto.tistory.com/entry/백준BOJC-20529번-가장-가까운-세-사람의-심리적-거리비둘기집-원리#google_vignette
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dis(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i)
        if (a[i] != b[i]) cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        int ans = 13; // 세 사람의 거리가 13보다 큰 값이 나올 수 없음
        int N; cin >> N;
        vector<string> arr;
        for (int i = 0; i < N; ++i) {
            string s; cin >> s;
            arr.push_back(s);
        }

        // 비둘기집의 원리
        // 17 ~ 32명일 때 최소 한 개의 MBTI 유형이 "두 명" 이상 존재
        // 32명 이상이면 최소 한 개의 MBTI 유형이 "세 명" 존재
        if (N > 32) { cout << "0\n"; continue; }

        // 브루트포스
        for (int i = 0; i < N - 2; ++i)
            for (int j = i + 1; j < N - 1; ++j)
                for (int k = j + 1; k < N; ++k)
                    ans = min(ans, dis(arr[i], arr[j]) + dis(arr[j], arr[k]) + dis(arr[i], arr[k]));
        cout << ans << "\n";
    }
    return 0;
}