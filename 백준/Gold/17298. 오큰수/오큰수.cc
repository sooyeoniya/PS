// 풀이 시간: 5m42s26(시간초과 최악의 경우 O(N^2)) + 9m28s12(스택)
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
// 참고: https://gyyeom.tistory.com/27
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N;
vector<int> arr, ans;
stack<int> s; // 스택 사용

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    arr = ans = vector<int>(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i < N; ++i) {
        // 스택이 비어있지 않고, 현재 값이 더 큰 경우
        while (!s.empty() && arr[s.top()] < arr[i]) {
            ans[s.top()] = arr[i]; // 현재 값을 스택(s.top())의 오큰수로 삽입
            s.pop(); // 더 이상 필요 없으므로 뺌 
        }
        s.push(i); // 스택에 인덱스 삽입
    }
    // 스택이 비어있지 않으면, 스택에 남은 인덱스들은 다 오큰수가 없는 숫자들이므로 -1
    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}

// 5m42s26, 시간 초과 코드
// for (int i = 0; i < N; ++i) {
//     int cur = arr[i]; // 현재 수
//     int temp = -1; 
//     for (int j = i + 1; j < N; ++j) { // 왼쪽부터 검사
//         int comp = arr[j]; // 비교할 수
//         if (cur < comp) { temp = comp; break; } // 큰 수 발견하면 넣고 종료
//     }
//     ans.push_back(temp);
// }