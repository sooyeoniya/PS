// 풀이 시간: 15m39s94
// 시간 복잡도: O(M)
// 공간 복잡도: O(str.size())
// 참고 자료: https://donggoolosori.github.io/2020/09/24/boj-11723/
#include <iostream>
#include <string>
using namespace std;
int M, num, bit = 0;
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> M;
    while (M--) {
        cin >> str;
        if (str == "add") {
            cin >> num;
            // OR 연산자를 통해 num번째 자리수에 1 추가
            bit |= (1 << num);
        } else if (str == "remove") {
            cin >> num;
            // e.g. 1000 & ~(1000) = 0000
            bit &= ~(1 << num);
        } else if (str == "check") {
            cin >> num;
            if (bit & (1 << num)) cout << "1\n";
            else cout << "0\n";
        } else if (str == "toggle") {
            cin >> num;
            // bit의 num번째 자리수를 reverse
            bit ^= (1 << num);
        } else if (str == "all") {
            // 전부 111...111 로 바꿈
            bit = (1 << 21) - 1;
        } else if (str == "empty") {
            bit = 0;
        }
    }
    return 0;
}