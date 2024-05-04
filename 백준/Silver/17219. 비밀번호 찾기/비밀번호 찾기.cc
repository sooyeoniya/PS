#include <iostream>
#include <string>
#include <map>
using namespace std;
int N, M;
string a, b;
map<string, string> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        m[a] = b;
    }
    for (int i = 0; i < M; ++i) {
        cin >> a;
        cout << m[a] << "\n";
    }
    return 0;
}