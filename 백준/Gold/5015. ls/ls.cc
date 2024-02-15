#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
string P, S;
int N, arr[101][101];

int find(int x, int y) {
   int& result = arr[x][y];
   if (result != -1) return result;

   if (x < P.size() && y < S.size() && P[x] == S[y])
      return result = find(x + 1, y + 1);

   if (x == P.size() && y == S.size()) 
      return result = true;

   if (P[x] == '*')
      return result = (find(x + 1, y) || find(x, y + 1));

   return result = false;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> P >> N;
   vector<string> ans;

   for (int i = 0; i < N; ++i) {
      cin >> S;
      memset(arr, -1, sizeof(arr));
      if (find(0, 0)) ans.push_back(S);
   }
   
   for (int i = 0; i < ans.size(); ++i)
      cout << ans[i] << "\n";
   return 0;
}