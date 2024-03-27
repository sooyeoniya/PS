#include <iostream>
using namespace std;

int gcd(int x, int y) {
    return x % y ? gcd(y, x % y) : y;
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x, y; cin >> x >> y;
    cout << gcd(x, y) << "\n" << lcm(x, y);
    return 0;
}