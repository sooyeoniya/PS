// 풀이 시간: 35m24s50
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	deque<int> dq;
	for (int i = 0; i < N; ++i) {
		string str; cin >> str;
		if (str == "push_back" || str == "push_front") {
			int num; cin >> num;
			if (str == "push_back") dq.push_back(num);
			else dq.push_front(num);
		}
		else {
			if (str == "front") {
				if(!dq.empty()) cout << dq.front() << "\n";
				else cout << "-1\n";
			}
			if (str == "back") {
				if(!dq.empty()) cout << dq.back() << "\n";
				else cout << "-1\n";
			}
			if (str == "size") cout << dq.size() << "\n";
			if (str == "empty") {
				if (dq.empty()) cout << "1\n";
				else cout << "0\n";
			}
			if (str == "pop_front") {
				if (!dq.empty()) {
					cout << dq.front() << "\n";
					dq.pop_front();
				}
				else cout << "-1\n";
			}
			if (str == "pop_back") {
				if (!dq.empty()) {
					cout << dq.back() << "\n";
					dq.pop_back();
				}
				else cout << "-1\n";
			}
		}
	}
	return 0;
}
