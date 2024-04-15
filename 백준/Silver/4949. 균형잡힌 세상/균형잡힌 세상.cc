// 풀이 시간: 16m54s01
// 시간 복잡도: O(CN) // C: 총 문자열 개수, N: 문자열 str의 크기
// 공간 복잡도: O(N) // N: 문자열 str의 크기
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (1) {
        string str; getline(cin, str); // 개행문자를 기준으로 나눔
        if (str.size() == 1 && str[0] == '.') break;

        stack<char> s;
        bool check = true;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(') s.push('(');
            if (str[i] == ')') {
                if (!s.empty() && s.top() == '(') s.pop();
                else { check = false; break; }
            }
            if (str[i] == '[') s.push('[');
            if (str[i] == ']') {
                if (!s.empty() && s.top() == '[') s.pop();
                else { check = false; break; }
            }
        }
        if (check && s.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}