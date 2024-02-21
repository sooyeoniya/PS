#include <iostream>
#include <vector>
using namespace std;
int D1, D2, cnt = 0;
vector<int> arr;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> D1 >> D2;
   arr = vector<int>(D2 + 1);
   
   for (int i = D1; i <= D2; ++i) {
      arr[i] = i;
      if (i != D1) {
         bool divisor = false;
         for (int j = D1; j < i; ++j) { // 약수 계산 D1 = 3, i = 6
            if (i % j == 0) { // 6 % 3 == 0
               divisor = true; // 약수 하나라도 존재함
               arr[i] -= arr[j];
            }
         }
         // D1 이상의 i의 약수가 존재하지 않을 경우
         if (!divisor) arr[i] = i - 1;
      }
      cnt += arr[i];
   }
   cout << cnt;
   return 0;
}