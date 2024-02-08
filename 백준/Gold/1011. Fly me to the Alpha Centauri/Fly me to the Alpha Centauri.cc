// 2021.02.04 이전 코드
// #include <stdio.h>

// int main() {
// 	int t;
// 	long x, y;
// 	scanf("%d", &t);
// 	for (int i = 0; i < t; i++) {
// 		scanf("%ld %ld", &x, &y);
// 		long term = 0, turn = 0;
// 		for (long num = 0; num < y - x;) {
// 			term++;

// 			turn++;num += term;
// 			if (num >= y - x) break;

// 			turn++;num += term;
// 			if (num >= y - x) break;
// 		}
// 		printf("%ld\n", turn);
// 	}
// 	return 0;
// }

// 2024.02.08 코드 업데이트
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   int T; cin >> T;
   for (int i = 0; i < T; ++i) {
      long long x, y, distance = 0, cnt = 0, lightYear = 0;
      cin >> x >> y;
      do {
         lightYear++; // 이동 횟수(cnt)가 홀수일 때마다 이동 거리(lightYear) 1 추가
         cnt++; // 시작 무조건 1광년
         distance += lightYear; // 이동 거리 더함
         if (distance >= y - x) break; // 이동 거리가 목표 위치 도달 시 종료, 거리가 1광년일 수도 있음
         cnt++; // 마지막 무조건 1광년
         distance += lightYear; // 이동 거리 더함
      } while (distance < y - x); // 이동 거리가 목표 위치에 도달할 때까지 반복
      cout << cnt << "\n";
   }
   return 0;
}
