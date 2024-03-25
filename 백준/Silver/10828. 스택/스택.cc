// 풀이 시간: 3m54s87
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	stack<int> s;
	for (int i = 0; i < N; ++i) {
		string str; cin >> str;
		if (str == "push") {
			int X; cin >> X;
			s.push(X);
		}
		if (str == "pop") {
			if (!s.empty()) {
				cout << s.top() << "\n";
				s.pop();
			}
			else cout << "-1\n";
		}
		if (str == "size") {
			cout << s.size() << "\n";
		}
		if (str == "empty") {
			if (s.empty()) cout << "1\n";
			else cout << "0\n";
		}
		if (str == "top") {
			if (!s.empty()) cout << s.top() << "\n";
			else cout << "-1\n";
		}
	}
	return 0;
}