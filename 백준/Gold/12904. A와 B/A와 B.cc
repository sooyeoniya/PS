#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S, T;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> S >> T;

   while (S.size() < T.size()) {
      if (T[T.size() - 1] == 'A')
         T.pop_back();
      else if (T[T.size() - 1] == 'B') {
         T.pop_back();
         reverse(T.begin(), T.end());
      }
   }
   
   if (S == T) cout << 1;
   else cout << 0;
   return 0;
}