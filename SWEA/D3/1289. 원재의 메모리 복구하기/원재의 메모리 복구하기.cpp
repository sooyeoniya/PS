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
                else if (flag == 1 & str[j] == '0') { flag = 0; cnt++; }
            }
        }
        cout << "#" << i << " " << cnt << "\n";
    }
}
