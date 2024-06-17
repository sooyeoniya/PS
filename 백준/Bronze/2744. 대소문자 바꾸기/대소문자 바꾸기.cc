#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	string str; cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= 65 && str[i] <= 90) str[i] += 32;
		else str[i] -= 32;
	}
	cout << str;
}