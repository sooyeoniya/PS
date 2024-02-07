#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Trie {
   map<string, Trie*> child;

   void insert(vector<string>& food, int idx) {
      if (idx == food.size()) return; // food 문자열 배열을 전부 탐색했을 경우 반환
      if (child.find(food[idx]) == child.end()) // 해당 문자열이 존재하지 않으면, 해당 문자열 노드 생성
         child[food[idx]] = new Trie();
      child[food[idx]] -> insert(food, idx + 1);
   }

   void dfs(int depth) { // dfs로 child 탐색하여 정답 출력
      for (auto& ch : child) {
         for (int i = 0; i < depth; ++i) cout << "--";
         cout << ch.first << "\n";
         ch.second -> dfs(depth + 1);
         delete ch.second; // 메모리 해제
      }
   }
};

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   Trie* root = new Trie; // 루트 노드 생성
   int N; cin >> N;
   for (int i = 0; i < N; ++i) {
      int K; cin >> K; 
      vector<string> food(K); // 로봇 개미 한마리가 보내준 먹이 정보 K개 저장
      for (int j = 0; j < K; ++j) cin >> food[j];
      root -> insert(food, 0); 
   }
   root -> dfs(0);
   delete root; // 메모리 해제
   return 0;
}
