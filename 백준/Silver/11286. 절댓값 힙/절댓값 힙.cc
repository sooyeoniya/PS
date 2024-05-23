// 풀이 시간: 11m12s90
// 시간 복잡도: O(NlogN)
// 공간 복잡도: O(N)

// <풀이 과정>
// 참고 자료: 우선순위 큐 사용법 - https://kbj96.tistory.com/15
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        if(abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b); // > : 작은 값 우선, < : 큰 값 우선
    } 
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    priority_queue<int, vector<int>, cmp> pq;
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