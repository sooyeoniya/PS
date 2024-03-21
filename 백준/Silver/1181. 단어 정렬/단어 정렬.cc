#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// sort 함수 재정의
int cmp(string a, string b) {
	if (a.length() != b.length()) // 길이 순
		return a.length() < b.length();
	else return a < b; // 사전 순
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<string> W(N);
	for (int i = 0; i < N; ++i) cin >> W[i];
	sort(W.begin(), W.end(), cmp); // 정렬
	string before = ""; // 이전 값 저장
	for (int i = 0; i < N; ++i) {
		if (before == W[i]) continue; // 같은 문자열 중복 제거
		cout << W[i] << "\n";
		before = W[i];
	}
	return 0;
}