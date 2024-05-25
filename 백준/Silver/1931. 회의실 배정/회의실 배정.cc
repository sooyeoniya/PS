// 풀이 시간: 33m09s09
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)

// <풀이 과정>
// 분류: 그리디 알고리즘 -> 개어렵다;
// 참고 자료: https://cocoon1787.tistory.com/147
// 가장 빨리 끝나는 회의 시간 순서대로 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        arr.push_back({b, a});
    }
    sort(arr.begin(), arr.end());
    int ans = 1; // 첫 번째 회의 카운트
    int end = arr[0].first; // 첫 번째 회의가 끝나는 시각 (회의 중에 가장 빨리 끝나는 시각)
    for (int i = 1; i < N; ++i) {
        if (end <= arr[i].second) { // 그 다음 가장 빠른 회의 찾기
            ans++; // 회의 하나 추가
            end = arr[i].first;
        }
    }
    cout << ans;
    return 0;
}