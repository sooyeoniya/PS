// 48m54s11
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll; // long long 타입으로 변경
using namespace std;
ll N, M;
vector<int> arr; // 얘는 그냥 int 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        ll T; cin >> T;
        arr.push_back(T);
    }
    sort(arr.begin(), arr.end());
    ll l = 1, r = arr.back() * M; // 최대 시간
    while (l <= r) {
        ll m = (l + r) / 2;
        ll sum = 0; // 사람 수
        for (int i = 0; i < arr.size(); ++i) {
            sum += m / arr[i];
            if (sum > M) break;
        }
        if (sum >= M) r = m - 1; // 현재 시간 m에 대하여 사람 수가 충분히 넘쳐남 (시간 줄여도 됨)
        else l = m + 1; // 현재 시간 m에 대하여 심사 가능한 사람 수가 부족함 (시간이 더 필요)
    }
    cout << l; // l로 최종 값 수렴
    return 0;
}
