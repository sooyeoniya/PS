#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string str; cin >> str;
        cout << str[0] << str[str.size() - 1] << "\n";
    }
    return 0;
}