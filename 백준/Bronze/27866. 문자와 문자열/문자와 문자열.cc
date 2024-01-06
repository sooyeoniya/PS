#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	int i;
	cin >> s >> i;
	cout << s[i - 1];
	return 0;
}