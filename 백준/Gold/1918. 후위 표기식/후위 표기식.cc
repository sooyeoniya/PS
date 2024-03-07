#include <iostream>
#include <stack>
using namespace std;

int priority(char c) { // 문자의 우선순위 반환 (숫자가 클수록 우선순위 빠름)
	switch (c) {
      case '(': 
         return 0;
      case '+':
      case '-':
         return 1;
      case '*':
      case '/':
         return 2;
      default:
         break;
	}
}

int main() {
	stack<char> op; // 스택
	string str;	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') cout << str[i]; // 알파벳일 경우 바로 출력
		else if (str[i] == '(') op.push('('); // '('일 경우 스택에 삽입
		else if (str[i] == ')') { // ')'일 경우 '('가 나올때까지 스택의 맨 위 값을 출력하고 꺼내기
			while (op.top() != '(') {
				cout << op.top();
				op.pop();
			}
			op.pop(); // '('를 스택에서 삭제
		}
		else { // 그 외의 경우 op 스택이 비어있지 않을 때, 현재 연산자보다 우선순위가 빠른 연산자를 모두 꺼내어 출력
			while (!op.empty() && priority(op.top()) >= priority(str[i])) {
				cout << op.top();
				op.pop();
			}
			op.push(str[i]); // 현재 연산자 삽입
		}
	}

   // 남은 연산자 모두 삽입
	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
	return 0;
}