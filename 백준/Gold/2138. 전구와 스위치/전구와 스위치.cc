#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, ans = 1e9, cnt = 0; // min 함수 사용을 위해 ans 무한으로 초기화
string init, final, temp;

void solve(int first) {
   temp = init; // 다음 탐색 과정에서 기존 초기 값인 init 자체에 영향을 주지 않기 위해
   cnt = 0;
   if (first == 0) { // 첫 번째 값을 변경할 경우
      temp[0] = temp[0] == '0' ? '1' : '0';
      temp[1] = temp[1] == '0' ? '1' : '0';
      cnt++;
   }
   for (int i = 1; i < N; ++i) { // 인덱스 1번부터 마지막 (N - 1)번까지 탐색
      if (temp[i - 1] != final[i - 1]) { // 이전 값(i - 1)이 정답과 동일하지 않을 경우에만 변경
         temp[i - 1] = temp[i - 1] == '0' ? '1' : '0';
         temp[i] = temp[i] == '0' ? '1' : '0';
         if (i < N - 1) temp[i + 1] = temp[i + 1] == '0' ? '1' : '0';
         cnt++;
      }
   }
   if (temp == final) ans = min(ans, cnt); // 정답과 일치할 경우 ans 갱신
}

int main() { 
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> init >> final;
   solve(0); solve(1); // 0: 첫 번째 값 변경, 1: 첫 번째 값 그대로 유지
   if (ans != 1e9) cout << ans; // ans 값이 갱신되었다면 출력
   else cout << -1; // 정답을 만들지 못했을 경우 -1
   return 0;
}
