// 풀이 시간: 29m13s95
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
// 참고 자료: https://rujang.tistory.com/entry/%EB%B0%B1%EC%A4%80-11399%EB%B2%88-ATM-CC
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, ans = 0; cin >> N;
    int people[1001] = { 0, };
    for (int i = 0; i < N; ++i) cin >> people[i];
    sort(people, people + N);
    for (int i = 0; i < N; ++i) ans += people[i] * (N - i);
    cout << ans;
    return 0;
}

// sort: [1, 2, 3, 3, 4]
// i = 0, ans = 1
// i = 1, ans = 1+(1+2)
// i = 2, ans = 1+(1+2)+(1+2+3)
// i = 3, ans = 1+(1+2)+(1+2+3)+(1+2+3+3)
// i = 4, ans = 1+(1+2)+(1+2+3)+(1+2+3+3)+(1+2+3+3+4)