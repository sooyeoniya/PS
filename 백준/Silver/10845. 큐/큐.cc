// 풀이 시간: 7m04s08
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	deque<int> dq;
	for (int i = 0; i < N; ++i) {
		string str; cin >> str;
		if (str == "push") {
			int X; cin >> X;
			dq.push_back(X);
		}
		if (str == "pop") {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else cout << "-1\n";
		}
		if (str == "size") cout << dq.size() << "\n";
		if (str == "empty") {
			if (dq.empty()) cout << "1\n";
			else cout << "0\n";
		}
		if (str == "front") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.front() << "\n";
		}
		if (str == "back") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.back() << "\n";
		}
	}
	return 0;
}