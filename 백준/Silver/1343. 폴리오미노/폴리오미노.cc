// 풀이 시간: 18m39s37
#include <iostream>
#include <string>
using namespace std;
int cnt = 0;
string str, ans = "";

bool check() {
	while (cnt >= 4) {
		ans += "AAAA";
		cnt -= 4;
	}
	while (cnt >= 2) {
		ans += "BB";
		cnt -= 2;
	}
	if (cnt > 0) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'X') cnt++;
		else {
			if (check()) break;
			ans += str[i];
			cnt = 0;
		}
	}
	if (check()) cout << -1;
	else cout << ans;
	return 0;
}