#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int scale[8] = { 0, }, ascending = 0, descending = 0;
    for (int i = 0; i < 8; i++) {
        cin >> scale[i];
        if (scale[0] == 1 && scale[i] == i + 1) ascending++;
        else if (scale[0] == 8 && scale[i] == 8 - i) descending++;
    }
    if (ascending == 8) cout << "ascending";
    else if (descending == 8) cout << "descending";
    else cout << "mixed";
    return 0;
}