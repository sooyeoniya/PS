// 풀이 시간: 6m18s62
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a; 
        arr.push_back(a);
    }

    sort (arr.begin(), arr.end());

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a; cin >> a;
        int l = 0, r = arr.size() - 1, m;
        bool check = false;
        while (l <= r) {
            m = (l + r) / 2;
            if (arr[m] > a) r = m - 1;
            else if (arr[m] < a) l = m + 1;
            else { check = true; break; }
        }
        if (check) cout << "1 ";
        else cout << "0 ";
    }

    return 0;
}
