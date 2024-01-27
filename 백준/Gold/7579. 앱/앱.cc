#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int m[101] = { 0, };
int c[101] = { 0, };
int dp[101][10001] = { 0, };
int result = 1000000000;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++){
		cin >> m[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (c[i] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
			else
				dp[i][j] = dp[i - 1][j];

			if (dp[i][j] >= M) result = min(result, j);
		}
	}
	

	cout << result << endl;

	return 0;
}