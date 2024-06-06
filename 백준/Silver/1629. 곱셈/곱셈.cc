// 참고: https://velog.io/@junttang/BOJ-1629-곱셈-해결-전략-C
#include <iostream>
using namespace std;
long long A, B, C, K;

long long power(long long B) {
    if (B == 0) return 1;
    if (B == 1) return A % C;
    K = power(B / 2) % C;
    if (B % 2 == 0) return K * K % C;
    return K * K % C * A % C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> A >> B >> C;
    cout << power(B);
    return 0;
}