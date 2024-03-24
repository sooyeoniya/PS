// 풀이 시간:7m35s98 
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
#include <iostream>
#include <queue>
using namespace std;

struct Sort {
	int x, y;
	Sort(int _x, int _y) : x(_x), y(_y) {}
	bool operator<(const Sort& other) const {
		if (x != other.x) return x > other.x;
		else return y > other.y;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	priority_queue<Sort> pq;
	for (int i = 0; i < N; ++i) {
		int x, y; cin >> x >> y;
		pq.push({x, y});
	}
	for (int i = 0; i < N; ++i) {
		cout << pq.top().x << " " << pq.top().y << "\n";
		pq.pop();
	}
	return 0;
}