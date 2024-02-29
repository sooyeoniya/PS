#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> parent;

class Edge {
   public:
      int node[2], cost;
      Edge(int A, int B, int cost) {
         this->node[0] = A;
         this->node[1] = B;
         this->cost = cost;
      }

      // 오름차순 정렬 시 cost(유지비)를 기준으로 정렬
      // bool operator<(Edge &edge) { return this->cost < edge.cost; }
      bool operator<(const Edge &edge) const { return this->cost < edge.cost; }
};

// 재귀를 통해 부모노드 가져오기
int getParent(int node) {
   if (parent[node] == node) return node;
   else return getParent(parent[node]);
}

// 노드끼리 연결, 더 작은 부모노드로 변경
void unionParent(int node1, int node2) {
   node1 = getParent(node1);
   node2 = getParent(node2);
   if (node1 < node2) parent[node2] = node1;
   else parent[node1] = node2;
}

// 사이클인지 판단
bool isCycle(int node1, int node2) {
   node1 = getParent(node1);
   node2 = getParent(node2);
   if (node1 == node2) return true;
   else return false;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> M;
   parent = vector<int>(N + 1, 0);
   vector<Edge> v;
   for (int i = 1; i <= N; ++i) parent[i] = i; // 부모노드 초기화
   for (int i = 0; i < M; ++i) { // 전체 노드들의 간선 추가
      int A, B, C; cin >> A >> B >> C;
      v.push_back(Edge(A, B, C));
   }
   // 오름차순 정렬(작은 값부터 더해주기 위함)
   sort(v.begin(), v.end());

   int sum = 0, maxCost = 0;
   for (int i = 0; i < v.size(); ++i) {
      // 사이클이 존재하지 않을 경우 유지비 더함
      if (!isCycle(v[i].node[0], v[i].node[1])) {
         sum += v[i].cost;
         maxCost = v[i].cost;
         unionParent(v[i].node[0], v[i].node[1]);
      }
   }
   sum -= maxCost; // 마지막으로 더한 가장 큰 유지비를 뺌
   cout << sum;
   return 0;
}