#include <iostream>
#include <vector>
using namespace std;
int N, T, P, cnt;
int arr[6] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < 6; ++i) cin >> arr[i];
    cin >> T >> P;
    for (int i = 0; i < 6; ++i) {
        cnt += arr[i] / T;
        if (arr[i] % T != 0) cnt++;
    }
    cout << cnt << "\n" << N / P << " " << N % P;
    return 0;
}