#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <climits>
using namespace std;
long long N;
vector<long long> arr;

void check() {
   long long featureValue = 1e18; // 특성값, int의 최댓값 1e9, long long의 최댓값 1e18
   long long ans1, ans2, ans3; // 출력값
   for (int i = 0; i < N - 2; ++i) { // i가 가장 작은 값
      long long left = i + 1; // left가 중간 값
      long long right = N - 1; // right가 가장 큰 값
      while (left < right) {
         long long sum = arr[i] + arr[left] + arr[right];

         if (abs(sum) < featureValue) {
            featureValue = abs(sum);
            ans1 = arr[i];
            ans2 = arr[left];
            ans3 = arr[right];
         }

         if (sum < 0) left++;
         else right--;
      }
   }
   // 출력
   cout << ans1 << " " << ans2 << " " << ans3 << "\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N;
   arr = vector<long long>(N, 0);
   for (int i = 0; i < N; ++i) cin >> arr[i];
   sort(arr.begin(), arr.end()); // 정렬
   check();
   return 0;
}