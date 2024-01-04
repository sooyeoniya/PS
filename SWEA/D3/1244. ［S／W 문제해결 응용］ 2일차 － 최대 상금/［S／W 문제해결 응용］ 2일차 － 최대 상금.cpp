/**
* 풀이 시간: 1h06m20s
* 시간 복잡도: O(N^2 * M) -> N: 문자열 길이, M: 교환 횟수
* 공간 복잡도: O(1) -> 상수 값에 의존
* 오류 원인: result 값을 따로 출력하지 않고 그냥 max(result, stoi(str)) 부분을 그대로 리턴해 출력하려고 함
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str; // 입력된 숫자를 string으로 저장
int result, num; // 결괏값, 교환 횟수

void dfs(int n, int curNum) {
    // 교환 횟수가 모두 다 끝났을 경우, 가장 큰 값 저장. stoi(str): string -> int
    if (num == curNum) { result = max(result, stoi(str)); return; }

    // 시작 시 n(i)번째부터 시작하여, 재귀함수 호출 시 시간 단축
    for (int i = n; i < str.size() - 1; i++) {
        for (int j = i + 1; j < str.size(); j++) {
            swap(str[i], str[j]);
            dfs(i, curNum + 1); // 현재 교환 횟수를 증가시켜 dfs 재귀 호출
            swap(str[i], str[j]); // 다음 시작점(i)을 위해 문자열 원상 복구
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int C; cin >> C;
    for (int i = 1; i <= C; i++) {
        result = 0;
        cin >> str >> num;


        /*
        만약 교환 횟수가 문자열 크기보다 크다면 
        문자열 길이를 넘어가는 교환은 기존 숫자와 동일한 숫자를 얻을 뿐이고
        시간 초과가 날 가능성이 높음(이 부분을 추가했더니 시간초과 안남)
        따라서, 교환 횟수를 문자열 크기 값으로 설정
        */
        if (num > str.size()) num = str.size();

        dfs(0, 0);
        cout << "#" << i << " " << result << "\n";
    }
}