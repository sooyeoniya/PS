#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int A, ans = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> A;
        ans += A;
    }
    cout << ans;
    return 0;
}