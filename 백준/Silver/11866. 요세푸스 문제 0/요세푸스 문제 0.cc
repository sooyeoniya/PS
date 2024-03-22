// 풀이 시간: 38m17s60
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	deque<int> dq, tempN; // 요세푸스 순열 저장, 임시 N 배열
	
	int num = 1;
	while (num <= N) {
		tempN.push_back(num);
		num++;
	}

	int curIdx = 0; // 현재 위치
	while (!tempN.empty()) {
		curIdx = (curIdx + K - 1) % tempN.size(); // 현재 위치를 K 만큼 건너뛰고 갱신
		dq.push_back(tempN[curIdx]); // dq에 넣기
		tempN.erase(tempN.begin() + curIdx); // curIdx 위치 값 제거
	}

	// 출력
	cout << "<";
	while (dq.size() > 1) {
		cout << dq.front() << ", ";
		dq.pop_front();
	}
	cout << dq.front() << ">";
	return 0;
}