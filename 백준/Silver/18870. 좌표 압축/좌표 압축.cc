// 풀이 시간: 36m38s46
// 시간 복잡도: O(NlogN) // 정렬 함수 logN
// 공간 복잡도: O(N)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int, long long>> ans; // 순서, 값
vector<long long> arr; // long long 타입으로 저장

// sort 함수 오버라이딩, 인자 중요 (const [타입]& [인자이름])
bool cmp(const pair<int, long long>& a, const pair<int, long long>& b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    arr = vector<long long>(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i < N; ++i) ans.push_back({i, arr[i]}); // 순서, 값 저장
    sort(ans.begin(), ans.end(), cmp); // 값 오름차순 정렬
    
    int prev = 1e9 + 1, cnt = -1; // prev 범위를 1e9 + 1로 해야 제한에 안걸림
    for (int i = 0; i < N; ++i) {
        if (prev != ans[i].second) cnt++; // 이전 값과 동일하지 않을 경우에만 cnt++
        prev = ans[i].second; // 이전 값 저장
        ans[i].second = cnt; // 값을 자신보다 작은 값의 수로 갱신
    }
    sort(ans.begin(), ans.end()); // 순서 오름차순 정렬
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].second << " ";
    return 0;
}