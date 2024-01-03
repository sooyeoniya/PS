// 풀이 시간: 1시간 - 처음에 bit 값을 그대로 받으려다가 string 라이브러리로 바꾸는 과정에서 시간 소요
// 시간 복잡도: O(T*N) - N은 str 문자열의 길이
// 공간 복잡도: O(1) - 전부 상수 값이므로
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        string str;
        int cnt = 0, flag = 0;
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            if (j == 0) {
                if (str[j] == '1') { flag = 1; cnt++; }
                else continue;
            }
            else {
                if (flag == 0 & str[j] == '1') { flag = 1; cnt++; }
                if (flag == 1 & str[j] == '0') { flag = 0; cnt++; }
            }
        }
        cout << "#" << i << " " << cnt << "\n";
    }
}
