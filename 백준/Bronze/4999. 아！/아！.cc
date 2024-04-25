#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string a, b; cin >> a >> b;
    if (a.size() >= b.size()) cout << "go";
    else cout << "no";
    return 0;
}