// 풀이 시간: 10m37s48
// 시간 복잡도: O(n)
// 공간 복잡도: O(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n == 0) { cout << "0"; return 0; }
    arr = vector<int>(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int num = round(n * 0.15);
    double sum = 0;
    for (int i = num; i < n - num; ++i) sum += arr[i];
    int avg = round(sum / (n - 2 * num));
    cout << avg;
    return 0;
}
