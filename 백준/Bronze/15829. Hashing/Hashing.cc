// 풀이 시간: 18m34s51
// 시간 복잡도: O(L)
// 공간 복잡도: O(1)
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int L; cin >> L;
    long long h = 0, r = 1;
    for (int i = 0; i < L; ++i) {
        char c; cin >> c;
        h = (h + (c - 96) * r) % 1234567891;
        r = (31 * r) % 1234567891;
    }
    cout << h;
    return 0;
}