#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int N, M, ans = 0;
vector<string> setString;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> M;
   setString = vector<string>(N);
   for (int i = 0; i < N; ++i) cin >> setString[i];

   sort(setString.begin(), setString.end());

   for (int i = 0; i < M; ++i) {
      string str; cin >> str;
      int left = 0, right = N - 1;
      while (left <= right) {
         int mid = (left + right) / 2;
         if (str < setString[mid]) right = mid - 1;
         else if (str > setString[mid]) left = mid + 1;

         if (setString[mid].substr(0, str.size()) == str) { ans++; break; }
      }
   }
   cout << ans << "\n";
   return 0;
}