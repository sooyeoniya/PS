// 풀이 시간: 7m47s47
// 시간 복잡도: O(NlogN) - O(logN): top(), pop(), push() 연산
// 공간 복잡도: O(N)

// <풀이 과정>
// 참고 자료: 우선순위 큐 사용법 - https://kbj96.tistory.com/15
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq; // 작은 값 순으로 정렬
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        if (x == 0) {
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(x);
    }
    return 0;
}
