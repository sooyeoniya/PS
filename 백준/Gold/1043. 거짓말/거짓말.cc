// 유니온 파인드(Union-Find) 코드
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, T;
vector<int> parent;
vector<vector<int>> party;

int getParent(int node) { // 부모 노드 찾기
   if (parent[node] == node) return node;
   else return getParent(parent[node]);
}

void unionParent(int node1, int node2) { // 노드의 부모 통합
   node1 = getParent(node1);
   node2 = getParent(node2);
   // 더 작은 노드로 갱신
   if (node1 < node2) parent[node2] = node1;
   else parent[node1] = node2;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> M >> T;
   parent.resize(N + 1);
   party.resize(M);
   for (int i = 1; i <= N; ++i) parent[i] = i; // 부모 노드 초기화
   for (int i = 0; i < T; ++i) {
      int num; cin >> num;
      parent[num] = 0; // 진실을 아는 사람의 부모는 모두 0으로 설정
   }
   for (int i = 0; i < M; ++i) { // 파티 횟수
      int P; cin >> P; // 각 파티 인원 수
      int num, prev; // union 하기 위해 필요한 변수들
      for (int j = 0; j < P; ++j) {
         if (j >= 1) { // 참석자가 1명일 경우를 대비해 조건문 생성
            prev = num; // 이전 번호 저장
            cin >> num; // 현재 번호 받기
            unionParent(prev, num); // 부모 통합
         }
         else cin >> num;
         party[i].push_back(num); // i번째 파티의 참석자 번호 저장
      }
   }
   int cnt = M; // 전체 파티 수
   // 부모가 0일 때 진실을 아는 사람이 해당 파티에 존재하므로 cnt--
   for (auto& p : party)
      for (auto& num : p)
         if (getParent(num) == 0)
            { cnt--; break; }
   cout << cnt;
   return 0;
}



/* 이전 코드 (그냥 구현)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M, knowsTruth, numOfPartyMembers, ans;
vector<bool> truth;
vector<vector<bool>> attendParty;

void check() {
   while (true) {
      bool isUpdated = false;
      for (int i = 1; i <= M; ++i) {
         bool truthInParty = false; 
         for (int j = 1; j <= N; ++j) {
            if (attendParty[i][j] && truth[j]) {
               truthInParty = true;
               break;
            }
         }
         // 현재 파티에 진실을 아는 자가 있을 경우 
         // 모든 파티원들의 truth 값을 true로 변경
         if (truthInParty) {
            for (int j = 1; j <= N; ++j) {
               if (attendParty[i][j] && !truth[j]) {
                  truth[j] = true;
                  isUpdated = true;
               }
            }
         }
      }
      if (!isUpdated) break;
   }
}

void updateAns() {
   // 모든 파티를 순회하며 현재 파티의 파티원 중 한명이라도 truth 값이 true면 break; 그 외에는 ans++
   for (int i = 1; i <= M; ++i) {
      bool truthInParty = false; 
      for (int j = 1; j <= N; ++j) {
         if (attendParty[i][j] && truth[j]) { 
            truthInParty = true; 
            break; 
         }
      }
      if (!truthInParty) ans++;
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> M >> knowsTruth;
   truth = vector<bool>(N + 1, false);
   attendParty = vector<vector<bool>>(M + 1, vector<bool>(N + 1, false));

   for (int i = 1; i <= knowsTruth; ++i) {
      int num; cin >> num;
      truth[num] = true; // 진실을 아는 사람
   }
 
   for (int i = 1; i <= M; ++i) {
      cin >> numOfPartyMembers;
      for (int j = 1; j <= numOfPartyMembers; ++j) {
         int num; cin >> num;
         attendParty[i][num] = true; // i번째 파티에 num이 참석
      }
   }

   check();
   updateAns();
   cout << ans << "\n";
   return 0;
}
*/
