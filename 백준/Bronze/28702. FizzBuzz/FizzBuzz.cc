// 풀이 시간: 16m19s

#include <iostream>
#include <string>
using namespace std;

void printOut(int num) {
    if (num % 3 == 0 && num % 5 == 0) cout << "FizzBuzz";
    else if (num % 3 == 0 && num % 5 != 0) cout << "Fizz";
    else if (num % 3 != 0 && num % 5 == 0) cout << "Buzz";
    else cout << num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    if (c[0] >= 48 && c[0] <= 57) printOut(stoi(c) + 1); // c가 숫자인 경우
    else if (b[0] >= 48 && b[0] <= 57) printOut(stoi(b) + 2); // b가 숫자인 경우
    else if (a[0] >= 48 && a[0] <= 57) printOut(stoi(a) + 3); // a가 숫자인 경우
    return 0;
}