#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    long long ans = 1;
    for (int i = N; i > 1; --i) ans *= i;
    cout << ans;
    return 0;
}