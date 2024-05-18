// 풀이 시간: 
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int ans = 0;
		int A, B, C; cin >> A >> B >> C;
		cout << "#" << test_case << " ";
		if (C == 1) { cout << "-1\n"; continue; }
		while (C <= B) { B--; ans++; }
		if (B == 1) { cout << "-1\n"; continue; }
		while (B <= A) { A--; ans++; }
		if (A <= 0) { cout << "-1\n"; continue; }
		cout << ans << "\n";
	}
	return 0;
}