// 풀이 시간: 22m44s62
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)

// <풀이 과정>
// '-'가 나오면 그 뒤에는 다 묶음. 그 다음 '-'가 나오기 전까지 숫자 계속 빼기
// 앞에서부터 차례대로 탐색
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string str; cin >> str;
    int num = 0, ans = 0;
    bool flag = false;
    for (int i = 0; i <= str.size(); ++i) { // 등호 사용
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0') { // 마지막 끝 문자열까지 처리해주기 위함
            if (flag) { // 이미 '-'가 나왔으면 빼줌
                ans -= num;
                num = 0;
            } else { // 일단 이전까지가 '+'이므로 더해주고, '-'가 나오면 flag 변경
                ans += num;
                num = 0;
                if (str[i] == '-') flag = true;
            }
        } else { // 현재 숫자 저장
            num *= 10;
            num += str[i] - '0';
        }
    }
    cout << ans;
    return 0;
}