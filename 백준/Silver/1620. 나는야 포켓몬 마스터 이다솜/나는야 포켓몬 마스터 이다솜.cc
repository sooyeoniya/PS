// 풀이 시간: 18m27s56
// 시간 복잡도: O(N+M)
// 공간 복잡도: O(N+M)
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<string, int> m;
vector<string> arr;
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr = vector<string>(N + 1);
    for (int i = 1; i < N + 1; ++i) {
        cin >> arr[i];
        m.insert({arr[i], i});
    }
    for (int i = 0; i < M; ++i) {
        string str; cin >> str;
        if (str[0] >= 65 && str[0] <= 90) // 영어 대문자 ASCII
            cout << m.find(str)->second << "\n";
        else cout << arr[stoi(str)] << "\n"; // string -> int 변환
    }
    return 0;
}