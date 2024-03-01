#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
bool visited[100001] = {false, };

void dijkstra() {
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, N});

   while (!pq.empty()) {
      int time = pq.top().first;
      int curX = pq.top().second;
      pq.pop();

      if (visited[curX]) continue;
      visited[curX] = true;

      if (curX == K) {
         cout << time;
         return;
      }

      if (curX - 1 >= 0)
         pq.push({time + 1, curX - 1});
      if (curX + 1 <= 100000)
         pq.push({time + 1, curX + 1});
      if (curX * 2 <= 100000)
         pq.push({time, curX * 2});
   }
}

int main() { 
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> K;
   dijkstra();
   return 0;
}
