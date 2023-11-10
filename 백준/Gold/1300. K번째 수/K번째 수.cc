#include <iostream>
using namespace std;

long n, k;

int binary_search(long n, long k) { // https://st-lab.tistory.com/281
	
	long mid = 0, left = 1, right = k;
	while (left < right) {
		long sum = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= n; i++) sum += min(mid / i, n);
		if (sum >= k) right = mid;
		else left = mid + 1;
	}
	return left; // lower-bound
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	cout << binary_search(n, k) << "\n";
}