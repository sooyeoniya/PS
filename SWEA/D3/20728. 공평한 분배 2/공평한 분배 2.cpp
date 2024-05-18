// 풀이 시간: 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, ans, minNum;
vector<int> arr;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		ans = 1e9;
		cin >> N >> K;
		arr = vector<int>(N, 0);
		for (int i = 0; i < N; ++i) cin >> arr[i];
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size(); ++i)
			if (i + (K - 1) < arr.size())
				ans = min(ans, arr[i + (K - 1)] - arr[i]);
		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}