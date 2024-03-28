// 참고 코드: https://gdlovehush.tistory.com/306
// 소인수분해 방식
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, cnt = 0; cin >> N;
    for (int i = 5; i <= N; i *= 5) cnt += N / i;
    cout << cnt;    
    return 0;
}

// [시간 초과 코드] 무식하게 while문 돌리면 자릿수 때문에 당연히 시간초과...
// 풀이 시간: 10m
// #include <iostream>
// #include <cmath> // pow 함수
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     int N, sum = 1, zero = 0; cin >> N;
//     while (N > 0) { sum *= N; N--; }
//     while (1) {
//         if (sum % 10 != 0) break;
//         else {
//             sum /= 10;
//             zero++;
//         }
//     }
//     cout << zero;
//     return 0;
// }