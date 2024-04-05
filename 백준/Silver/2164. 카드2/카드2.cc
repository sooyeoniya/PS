// 풀이 시간: 4m48s81
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    deque<int> dq;
    for (int i = 0; i < N; ++i) dq.push_back(i + 1);
    while (dq.size() != 1) {
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout << dq.front();
    return 0;
}