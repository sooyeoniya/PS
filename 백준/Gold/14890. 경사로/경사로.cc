#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, L, ans = 0;
vector<bool> cnt1, cnt2;
int arr1[101][101] = { 0, };
int arr2[101][101] = { 0, };

vector<bool> isRoad(int arr[][101]) {
    vector<bool> cnt(N, true);
    bool ramp[101][101] = { false, }; // 경사로 설치
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            if (arr[i][j] == arr[i][j + 1]) continue; // 같은 높이일 경우 continue
            else if (abs(arr[i][j] - arr[i][j + 1]) == 1) { // 크기 1차이
                if (arr[i][j] > arr[i][j + 1]) {
                    ramp[i][j + 1] = true;
                    for (int k = j + 1; k < j + 1 + L; ++k) {
                        if (k >= N || arr[i][j + 1] != arr[i][k]) 
                            { cnt[i] = false; break; }
                        else ramp[i][k] = true;
                    }
                }
                else {
                    for (int k = j; k > j - L; --k) {
                        if (k < 0 || arr[i][j] != arr[i][k])
                            {  cnt[i] = false; break; }
                        else {
                            if (!ramp[i][k]) ramp[i][k] = true;
                            else { cnt[i] = false; break; }
                        }
                    }
                }
            }
            else { cnt[i] = false; break; } // 값의 차이가 2일 경우 false 후 해당 길 종료
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> L;
    cnt1 = cnt2 = vector<bool>(N, true);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> arr1[i][j];
            arr2[j][i] = arr1[i][j];
        }
    cnt1 = isRoad(arr1);
    cnt2 = isRoad(arr2);
    for (int i = 0; i < N; ++i) {
        if (cnt1[i]) ans++;
        if (cnt2[i]) ans++;
    }
    cout << ans;
    return 0;
}