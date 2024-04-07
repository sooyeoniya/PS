// 풀이 시간: 48m37s05
// 시간 복잡도: O(n)
// 공간 복잡도: O(n)
// 참고 자료: https://gaeunhan.tistory.com/16
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int num = 1;
    stack<int> s;
    vector<char> ans;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        while (num <= x) {
			s.push(num);
			num++;
			ans.push_back('+');
		}
		if (s.top() == x) {
			s.pop();
			ans.push_back('-');
		} else {
			cout << "NO";
			return 0;
		}
    }
    for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << "\n";
	}
    return 0;
}
