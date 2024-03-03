// 최신 코드 (트라이)
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int N, M, cnt = 0;

struct Trie {
   Trie* child[26]; // 자식 노드 생성
   Trie() { for (int i = 0; i < 26; ++i) child[i] = NULL; }

   void insert(string& str, int idx) {
      if (idx == str.size()) return; // 문자열 끝에 도달했을 경우 반환
      if (child[str[idx] - 'a'] == NULL) // 자식이 없을 경우 현재 문자의 자식 노드 생성
         child[str[idx] - 'a'] = new Trie();
      child[str[idx] - 'a'] -> insert(str, idx + 1); // 다음 문자 삽입을 위해 포인터로 호출
   }

   void search(string& str, int idx) {
      if (idx == str.size()) { cnt++; return; } // 문자열 끝에 도달했을 경우 검사 문자열이 존재하는 것이므로 cnt++
      if (child[str[idx] - 'a'] == NULL) return; // 검사 문자열의 현재 문자가 자식 노드 중에 없는 경우 접두사가 될 수 없으므로 반환
      child[str[idx] - 'a'] -> search(str, idx + 1); // 자식 노드 중에 있는 경우 다음 위치의 문자 검사를 위해 재귀 호출
   }
};

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> M;
   Trie* root = new Trie; // 루트 노드 생성
   for (int i = 0; i < N; ++i) {
      string str; cin >> str;
      root -> insert(str, 0); // 집합 S에 있는 N개의 문자열 각각 삽입
   }
   for (int i = 0; i < M; ++i) {
      string str; cin >> str;
      root -> search(str, 0); // 검사할 M개의 문자열 각각 탐색
   }
   cout << cnt;
   delete root;
   return 0;
}


// 이전 코드 (이분 탐색)
// 풀이 시간: 31m38s90
// 시간 복잡도: O(NlogN + MlogN) - NlogN: 문자열 입력 받은 후 정렬, MlogN: 각 문자열에 대해 이분탐색
// 공간 복잡도: O(NL) - L: 문자열 최대 길이

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
