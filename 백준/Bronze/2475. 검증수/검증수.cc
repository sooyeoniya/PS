#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int arr[5], result = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		result += arr[i] * arr[i];
	}
	cout << result % 10;
	return 0;
}