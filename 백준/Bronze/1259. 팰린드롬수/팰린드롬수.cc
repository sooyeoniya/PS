// 풀이 시간: 22m28s34
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string N = "";
	while (1) {
		cin >> N;
		if (N[0] == '0') break;
		deque<int> dq;
		for (int i = 0; i < N.size(); ++i)
			dq.push_back(N[i] - '0');
		bool isPalindrome = true;
		// 비어있거나 한 개 남았을 때는 while문 돌지 않음
		while (!dq.empty() && dq.size() > 1) {
			// 앞뒷 값이 다르면 종료
			if (dq.front() != dq.back()) {
				isPalindrome = false;
				break;
			}
			dq.pop_front();
			dq.pop_back();
		}
		if (isPalindrome)
			cout << "yes" << "\n";
		else 
			cout << "no" << "\n";
	}
	return 0;
}