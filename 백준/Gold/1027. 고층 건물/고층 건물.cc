// 풀이 시간: 1h30m55s54
// 시간 복잡도: O(N^2)
// 공간 복잡도: O(N)

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N, ans = 0;
int arr[51] = { 0, };

bool findBuilding(int i, int j) {
    if (i > j) swap(i, j); // 항상 (i < j)로 계산
    for (int k = i + 1; k < j; ++k) { 
        double height = arr[i] + double(arr[i] - arr[j]) * (k - i) / (i - j); // 높이 (타입 유의)
        if (height <= arr[k]) return false; // 해당 선분에 어떤 고층빌딩도 지나가면 안되기 때문에 같은 높이도 안됨
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    for (int i = 1; i <= N; ++i) {
        int cnt = 0;
        for (int j = 1; j <= N; ++j) {
            if (i == j) continue;
            if (findBuilding(i, j)) cnt++; // 해당 빌딩이 보이면 카운트
        }
        ans = max(cnt, ans);
    }
    cout << ans;
    return 0;
}