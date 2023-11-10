#include <iostream>
using namespace std;

int n, m;
string name[100000];
int power[100000];

int binary_search(int x) { // https://cjh5414.github.io/binary-search/
	int left = 0, right = n - 1, mid = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		if (x <= power[mid]) right = mid - 1;
		else left = mid + 1;
	}
	if (x > power[mid]) return mid + 1;
	else return mid;
}

int main(void) {
	ios_base::sync_with_stdio(false); // https://leeeegun.tistory.com/4
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> name[i] >> power[i];

	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cout << name[binary_search(x)] << "\n";
	}
}