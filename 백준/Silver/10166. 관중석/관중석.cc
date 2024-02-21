#include <iostream>
#include <vector>
using namespace std;
int D1, D2, cnt = 0;
bool check[2001][2001];

// 최대 공약수
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> D1 >> D2;
   for (int i = D1; i <= D2; ++i) {
      for (int j = 1; j <= i; ++j) {
         int g = gcd(i, j);
         int x = j / g, y = i / g;
         if(check[x][y] == 0) {
            check[x][y] = true;
            cnt++;
         }
      }
   }
   cout << cnt;
   return 0;
}