#include <iostream>
#include <vector>
using namespace std;
int D1, D2, cnt = 0;
bool check[2001][2001];

// 최대 공약수 계산
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> D1 >> D2;
   for (int i = D1; i <= D2; ++i) {
      for (int j = 1; j <= i; ++j) {
         int g = gcd(i, j); // i, j의 공통 최대 공약수, 즉, j부터 1까지 중 i의 최대 공약수 반환
         int x = j / g, y = i / g; // (x/y) 형태의 기약분수
         if(!check[x][y]) { // 해당 기약분수에 아직 좌석이 존재하지 않을 경우
            check[x][y] = true;
            cnt++;
         }
      }
   }
   cout << cnt;
   return 0;
}
