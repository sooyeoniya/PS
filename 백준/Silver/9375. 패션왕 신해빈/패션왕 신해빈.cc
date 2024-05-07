// 참고: https://donggoolosori.github.io/2020/10/05/boj-9375/
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        map<string, int> m;
        while (N--) {
            string a, b;
            cin >> a >> b;
            if (m.find(b) == m.end())
                m.insert({b, 1});
            else m[b]++;
        }
        int ans = 1;
        for (auto i : m) {
            ans *= (i.second + 1);
        }
        ans--;
        cout << ans << "\n";
    }
    return 0;
}