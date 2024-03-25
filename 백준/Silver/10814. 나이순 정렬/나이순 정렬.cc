// 풀이 시간: 11m15s66
// 시간 복잡도: O(NlogN)
// 공간 복잡도: O(N)
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Age {
	int index, age;
	string name;
	Age (int _index, int _age, string _name) : index(_index), age(_age), name(_name) {}

	bool operator<(const Age& other) const {
		if (age != other.age) return age > other.age;
		else return index > other.index;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	priority_queue<Age> pq;
	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		int age;
		string name; 
		cin >> age >> name;
		pq.push({i, age, name});
	}
	for (int i = 0; i < N; ++i) {
		cout << pq.top().age << " " << pq.top().name << "\n";
		pq.pop();
	}
	return 0;
}