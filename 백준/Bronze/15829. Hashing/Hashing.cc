#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int L; cin >> L;
    long long l = 0;
    for (int i = 0; i < L; ++i) {
        char c; cin >> c;
        l += (c - 96) * pow(31, i);
    }
    cout << l % 1234567891;
    return 0;
}