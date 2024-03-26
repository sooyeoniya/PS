// 풀이 시간: 4m13s04
// 시간 복잡도: O(N)
// 공간 복잡도: O(1)
#include <iostream>
using namespace std;
int N, K;

int factorial(int num) {
    int ans = 1;
    for (int i = num; i > 0; --i) ans *= i;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	cin >> N >> K;
    int ans = factorial(N) / (factorial(K) * factorial(N - K));
    cout << ans;
    return 0;
}