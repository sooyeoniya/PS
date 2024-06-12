#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b, c, d, e; 
    cin >> a >> b >> c;
    int ham = min({a, b, c});
    cin >> d >> e;
    int drink = min(d, e);
    cout << ham + drink - 50;
    return 0;
}