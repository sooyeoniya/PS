#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int K; cin >> K;
	deque<int> dq;
	for (int i = 0; i < K; ++i) {
		int X; cin >> X;
		if (X == 0) dq.pop_back();
		else dq.push_back(X);
	}
	int sum = 0;
	while (!dq.empty()) {
		sum += dq.front();
		dq.pop_front();
	}
	cout << sum;
	return 0;
}