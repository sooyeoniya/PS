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
      for (int j = 1; j <= 50; ++j) {
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
