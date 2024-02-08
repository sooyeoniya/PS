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
   long long ans1, ans2; // 출력값
   long long left = 0; // 가장 작은 값
   long long right = N - 1; // 가장 큰 값
   while (left < right) { // 
      long long sum = arr[left] + arr[right];

      if (abs(sum) < featureValue) { // 현재 특성값의 절댓값이 더 작을 경우 전부 갱신
         featureValue = abs(sum);
         ans1 = arr[left];
         ans2 = arr[right];
      }

      if (sum < 0) left++; // 현재 특성값이 0보다 작은 경우 left 인덱스 증가
      else right--; // 아닐 경우 right 인덱스 증가
   }
   // 출력
   cout << ans1 << " " << ans2 << "\n";
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