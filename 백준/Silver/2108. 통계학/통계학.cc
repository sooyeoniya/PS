// 풀이 시간: 43m40s
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool second = false;
int N, sum = 0, num[8001] = {0, };
int avg = 0, middle = 0, range = 0;
vector<int> arr;

int most() {
    int mostV, most = -9999;
    for (int i = 0; i < 8001; ++i) {
        if (num[i] == 0) continue;
        if (num[i] == most && second) {
            mostV = i - 4000;
            second = false;
        }
        if (num[i] > most) {
            most = num[i];
            mostV = i - 4000;
            second = true;
        }
    }
    return mostV;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    arr = vector<int>(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        sum += arr[i];
        num[arr[i]+4000]++;
    }
    avg = round((float)sum / N);
    sort(arr.begin(), arr.end()); // 정렬
    middle = arr[arr.size() / 2];
    range = arr.back() - arr.front();

    cout << avg << "\n"; // (1) 산술평균
    cout << middle << "\n"; // (2) 중앙값
    cout << most() << "\n"; // (3) 최빈값
    cout << range; // (4) 범위
    return 0;
}