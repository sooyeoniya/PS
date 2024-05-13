#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, M, ans = 0, sum = 0;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        sum = (sum + a) <= 0 ? 0 : (sum + a);
        if (sum >= M) ans++;
    }
    cout << ans;
    return 0;
}