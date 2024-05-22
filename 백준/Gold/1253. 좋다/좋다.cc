// 풀이 시간: 5m46s82(초기 풀이) + 18m47s04s
// 시간 복잡도: O(N^2)
// 공간 복잡도: O(N)

// <풀이 과정>
// 조합: 두 수를 더해서 good 벡터에 저장
// good에서 입력받은 수와 동일한 수가 있으면 하나씩 카운트
// 반례 67%) 자기 자신을 제외한 두 수를 뽑아야 함
// https://www.acmicpc.net/board/view/90205
// https://www.acmicpc.net/board/view/68348
// https://www.acmicpc.net/board/view/100953
// 유형: 투포인터 / 이분탐색 계산
// 참고 풀이: https://imnotabear.tistory.com/382
#include <iostream>
#include <algorithm>
using namespace std;
int N, val, ans = 0, arr[2000] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    for (int i = 0; i < N; ++i) {
        val = arr[i]; // 찾고자 하는 번호
        int l = 0, r = N - 1, sum;
        while (l < r) {
            sum = arr[l] + arr[r];
            if (sum == val) {
                if (l != i && r != i) { // 자기 자신이 아니어야 함
                    ans++;
                    break;
                }
                else if (l == i) l++;
                else if (r == i) r--;
            }
            else if (sum < val) l++;
            else r--;
        }
    }
    cout << ans;
    return 0;
}