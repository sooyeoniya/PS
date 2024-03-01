#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
bool visited[100001] = {false, };

void dijkstra() { // 우선순위 큐
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, N}); // {시간, 위치} 형태로 저장

   while (!pq.empty()) {
      int time = pq.top().first;
      int curX = pq.top().second;
      pq.pop();

      if (visited[curX]) continue; // 방문한 위치일 경우 건너뛰기
      visited[curX] = true;

      if (curX == K) { cout << time; return; } // 정답 위치에 도달했을 경우 출력
      if (curX - 1 >= 0) pq.push({time + 1, curX - 1}); // 1초 후 (X - 1)
      if (curX + 1 <= 100000) pq.push({time + 1, curX + 1}); // 1초 후 (X + 1)
      if (curX * 2 <= 100000) pq.push({time, curX * 2}); // 0초 후 (2 * X)
   }
}

int main() { 
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> K;
   dijkstra();
   return 0;
}
