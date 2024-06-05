#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    cout << stoi(a) + stoi(b) - stoi(c) << "\n";
    cout << stoi(a + b) - stoi(c) << "\n";
    return 0;
}