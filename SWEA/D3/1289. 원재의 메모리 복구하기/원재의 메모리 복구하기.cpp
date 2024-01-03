// 풀이 시간: 1시간 - 처음에 bit 값을 그대로 받으려다가 string 라이브러리로 바꾸는 과정에서 시간 소요
// 시간 복잡도: O(T*N) - N은 str 문자열의 길이
// 공간 복잡도: O(1) - 전부 상수 값이므로
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        string str; // 문자열을 string으로 저장
        int cnt = 0, flag = 0; // 개수 저장할 cnt 값, 현재 0인지 1인지 구분하는 flag 값
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            if (j == 0) { // 첫 번째 문자열 값 처리
                // 1일 경우 flag를 1로 바꾸고 cnt 값을 1 증가, 0일 경우 아무 것도 하지 않음(초깃값이 모든 bit가 0 이므로)
                if (str[j] == '1') { flag = 1; cnt++; }
                else continue;
            } else { // 첫 번째 문자열 외의 값 처리
                // flag가 0(이전 값이 0), 현재 문자열이 1일 경우, flag와 cnt 값 변경
                if (flag == 0 & str[j] == '1') { flag = 1; cnt++; }
                // flag가 1(이전 값이 1), 현재 문자열이 0일 경우, flag와 cnt 값 변경
                if (flag == 1 & str[j] == '0') { flag = 0; cnt++; }
            }
        }
        cout << "#" << i << " " << cnt << "\n";
    }
}
