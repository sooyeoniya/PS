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

// m: {{'A', 1}, {'B', 2}, ...}
// temp: ABC*+DE/-
// str: 123*+45/-

void solve() { // 후위 표기식 계산
   for (int i = 0; i < str.length(); ++i) {
      // 연산자일 경우 이전 두 개의 문자를 뽑아 현재 연산자를 사용해 계산 후 다시 스택에 저장
      if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
         double Y = st.top(); st.pop();
         double X = st.top(); st.pop();
         if (str[i] == '*') result = X * Y;
         else if (str[i] == '/') result = X / Y;
         else if (str[i] == '+') result = X + Y;
         else if (str[i] == '-') result = X - Y;
         st.push(result);
      }
      // 피연산자일 경우, 문자를 정수로 변환 후 저장 (e.g, '1' -> 1)
      else st.push(str[i] - '0'); // - '0' -> 문자를 정수로 변환
   }
}

void alter() { // 알파벳을 숫자로 대체
   for (int i = 0; i < temp.length(); ++i) {
      // 피연산자인 경우, 해당 알파벳에 대응하는 숫자를 찾아 str에 저장
      if (!(temp[i] == '*' || temp[i] == '/' || temp[i] == '+' || temp[i] == '-')) {
         char cur = m.find(temp[i])->second + '0'; // + '0' -> 값을 문자로 변환하여 저장
         str.push_back(cur); // str은 string이기 때문에 cur을 문자로 변환하여 저장
      }
      else str = str + temp[i]; // 연산자인 경우 그대로 저장
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N >> temp;

   // 알파벳에 대응하는 각 숫자를 map으로 저장
   char alpha = 'A';
   for (int i = 0; i < N; ++i) {
      int num; cin >> num;
      m.insert(make_pair(alpha, num));
      alpha++; // 아스키코드 1 증가
   }
   alter(); solve();
   cout << fixed << setprecision(2) << result << "\n"; // 소숫점 둘째 자리까지 출력
	return 0;
}
