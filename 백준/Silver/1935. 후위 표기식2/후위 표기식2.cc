#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
#include <map>
using namespace std;
int N;
double result = 0.0;
map<char, int> m;
string str = "", temp;
stack<double> st;

void solve() {
   for (int i = 0; i < str.length(); ++i) {
      if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
         double Y = st.top(); st.pop();
         double X = st.top(); st.pop();
         if (str[i] == '*') result = X * Y;
         else if (str[i] == '/') result = X / Y;
         else if (str[i] == '+') result = X + Y;
         else if (str[i] == '-') result = X - Y;
         st.push(result);
      }
      else st.push(str[i] - '0'); // - '0' -> 문자를 정수로 변환
   }
}

void alter() {
   for (int i = 0; i < temp.length(); ++i) {
      if (!(temp[i] == '*' || temp[i] == '/' || temp[i] == '+' || temp[i] == '-')) {
         char cur = m.find(temp[i])->second + '0'; // + '0' -> 값을 문자로 변환하여 저장
         str.push_back(cur);
      }
      else str = str + temp[i];
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> temp;

   char alpha = 'A';
   for (int i = 0; i < N; ++i) {
      int num; cin >> num;
      m.insert(make_pair(alpha, num));
      alpha++;
   }
   alter();
   solve();
   cout << fixed << setprecision(2) << result << "\n";
	return 0;
}