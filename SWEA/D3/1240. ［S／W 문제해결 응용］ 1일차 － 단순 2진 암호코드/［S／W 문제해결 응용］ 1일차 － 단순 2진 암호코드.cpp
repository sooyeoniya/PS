// 풀이 시간: 1h53m53s85
#include <iostream>
#include <string>
using namespace std;
int N, M, ans, start, last;
string str = "", code = "";
string scanner[10] = { "0001101", "0011001", "0010011", "0111101", 
"0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };

void calculation() {
	for (int i = 0; i < 56; i += 7) { // 암호코드 8개 확인
		string part = str.substr(start + i, 7); // 7개 문자 추출
		for (int k = 0; k < 10; ++k) { // scanner 9개 확인
			if (scanner[k] == part) {
				code += to_string(k);
				break;
			}
		}
	}
}

void isCorrect() {
	int odd = 0, even = 0; // 홀짝
	for (int i = 0; i < code.size(); ++i) {
		int num = code[i] - '0';
		if (i % 2 == 0) odd += num;
		else even += num;
	}
	int sum = odd * 3 + even;
	if (sum % 10 == 0) {
		for (int i = 0; i < code.size(); ++i)
			ans += code[i] - '0';
	}
	else ans = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		code = ""; str = ""; ans = 0; last = 0;
		cin >> N >> M;
		bool check = false;
		for (int i = 0; i < N; ++i) {
			string s; cin >> s;
			if (!check) {
				for (int j = s.size() - 1; j >= 0; --j)
					if (s[j] == '1') { str = s; last = j; check = true; break; }
			}
		}
		start = last - 55;
		calculation();
		isCorrect();
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}