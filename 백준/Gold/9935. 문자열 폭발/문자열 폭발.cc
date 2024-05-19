// 풀이 시간: 13m27s72((1번째풀이 시간초과: find, substr) + 26m33s40(2번째풀이 시간초과: maybe while문) + 7m10s63(참고풀이)
// 시간 복잡도: O(N * M) // N: str.size(), M: boom.size()
// 공간 복잡도: O(N + M) 
// 참고 자료: https://hagisilecoding.tistory.com/127
// Tip: 임시 문자열에 문자를 하나씩 추가하고 문자열 비교 
//      문자를 먼저 추가하고 거기서 비교해야 기존 문자열에서 폭발 문자열이 모두 걸러짐

#include <iostream>
#include <string>
using namespace std;
string str, boom, ans = "";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> str >> boom;
    for (int i = 0; i < str.size(); ++i) {
        ans += str[i];
        if (ans.size() >= boom.size()) {
            bool check = true;
            for (int j = 0; j < boom.size(); ++j) {
                if (ans[ans.size() - boom.size() + j] != boom[j]) {
                    check = false;
                    break;
                }
            }
            if (check) ans.erase(ans.end() - boom.size(), ans.end());
        }
    }
    if (ans.empty()) cout << "FRULA";
    else cout << ans;
    return 0;
}