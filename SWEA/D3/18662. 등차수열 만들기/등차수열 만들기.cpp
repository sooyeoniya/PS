#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		double a, b, c; cin >> a >> b >> c;
		double ans = 0.0;
		double left = b - a;
		double right = c - b;
		if (left != right) ans = abs(left - right) / 2;
		cout << "#" << test_case << " " << fixed << setprecision(1) << ans << "\n";
	}
	return 0;
}