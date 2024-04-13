// 풀이 시간: 16m11s68
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        string str; cin >> str;
        stack<char> s; 
        int size = 0;
        bool check = true;
        while (size < str.size()) {
            if (str[size] == ')') {
                if (!s.empty() && s.top() == '(') s.pop();
                else { check = false; break; }
            }
            else s.push(str[size]);
            size++;
        }
        if (!check || !s.empty()) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}