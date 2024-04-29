#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int N, M;
map<string, int> m;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string str; cin >> str;
        m.insert({str, 1});
    }
    for (int i = 0; i < M; ++i) {
        string str; cin >> str;
        if (m.find(str) != m.end()) {
            string s = m.find(str)->first;
            v.push_back(s);
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << "\n";
    return 0;
}