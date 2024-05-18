// 풀이 시간: 55m26s23
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
string str, str1, str2, ans;
vector<vector<bool>> dp, lp, rp;

bool isPal(int start, int end, int idx) {
	if (idx == 1) return (str[start] == str[end] && (dp[start + 1][end - 1] || end - start == 1));
	if (idx == 2) return (str1[start] == str1[end] && (lp[start + 1][end - 1] || end - start == 1));
	if (idx == 3) return (str2[start] == str2[end] && (rp[start + 1][end - 1] || end - start == 1));
}

void setDP() {
	for (int dis = 0; dis < str.size(); ++dis) {
		for (int begin = 0; begin + dis < str.size(); ++begin) {
			if (dis == 0) dp[begin][begin] = true;
			else if (isPal(begin, begin + dis, 1)) dp[begin][begin + dis] = true;
		}
	}
}

void setLP() {
	for (int dis = 0; dis < str1.size(); ++dis) {
		for (int begin = 0; begin + dis < str1.size(); ++begin) {
			if (dis == 0) lp[begin][begin] = true;
			else if (isPal(begin, begin + dis, 2)) lp[begin][begin + dis] = true;
		}
	}
}

void setRP() {
	for (int dis = 0; dis < str2.size(); ++dis) {
		for (int begin = 0; begin + dis < str2.size(); ++begin) {
			if (dis == 0) rp[begin][begin] = true;
			else if (isPal(begin, begin + dis, 3)) rp[begin][begin + dis] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		ans = "";
		cin >> str;
		N = str.size();
		str1 = str.substr(0, (N - 1) / 2);
		str2 = str.substr((N - 1) / 2 + 1, (N - 1) / 2);
		dp = vector<vector<bool>>(str.size(), vector<bool>(str.size(), false));
		lp = vector<vector<bool>>(str1.size(), vector<bool>(str1.size(), false));
		rp = vector<vector<bool>>(str2.size(), vector<bool>(str2.size(), false));
		setLP();
		setRP();
		setDP();

		if (lp[0][str1.size() - 1] && rp[0][str2.size() - 1] && dp[0][N - 1]) ans = "YES\n";
		else ans = "NO\n";
		cout << "#" << test_case << " " << ans;
	}
	return 0;
}
