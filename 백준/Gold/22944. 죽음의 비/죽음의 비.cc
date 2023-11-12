#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, h, d; // 정사각형 격자의 한 변의 길이 n, 현재 체력 h, 우산의 내구도 d
pair<int, int> Start, End; // 두 개의 값을 한 쌍으로 묶어서 관리하는 데이터 타입
vector<pair<int, int>> Umbrella; // pair<int, int> 타입의 요소를 가지는 동적 배열 vector
int ans = 1e9; // '무한대'를 나타내는 값, 10의 9제곱, 약 10억

void check_umbrella() {
	sort(Umbrella.begin(), Umbrella.end()); // 순열 next_permutation 함수를 사용하기 위해 오름차순 정렬
	do {
		int curY = Start.first; // 시작점의 행(y좌표)
		int curX = Start.second; // 시작점의 열(x좌표)
		int curH = h; // 현재 남은 체력
		int curU = 0; // 현재 우산의 내구도
		int moveCnt = 0; // 이동 횟수
		for (int i = 0; i < Umbrella.size(); i++) { // 우산이 있는 모든 위치를 순회
			int Y = Umbrella[i].first; // 다음 y좌표
			int X = Umbrella[i].second; // 다음 x좌표
			moveCnt += abs(curY - Y) + abs(curX - X);
			int damage = abs(curY - Y) + abs(curX - X) - curU; // 현재 이동할 거리 - 현재 우산의 내구도(피해량을 감소시켜줌)
			if (damage < 0) damage = 0; // 피해량이 음수가 되는 것을 방지
			curH -= damage; // 현재 체력에 피해를 입힘
			curU = d; // 이동 후 우산이 있는 위치에 도달, 현재 위치의 우산의 내구도로 재설정
			curY = Y; // y좌표 이동
			curX = X; // x좌표 이동
			
			if (make_pair(Y, X) == End) { // 현재 위치가 End에 도달했을 경우
				if (curH >= 0) ans = min(ans, moveCnt); // 남은 체력이 0보다 클 경우, ans와 현재 이동횟수를 비교하여 더 작은 값을 ans으로 설정
				break; // do-while 루프 나옴
			}
			else if (curH < 0) break; // End에 도달하지 않았는데 현재 체력이 0보다 작을 경우 do-while 루프 나옴
		}
	} while (next_permutation(Umbrella.begin(), Umbrella.end()));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> h >> d;

	for (int i = 0; i < n; i++) { // 각 행
		string s;
		cin >> s; // 입력받은 문자열들 (한 행씩 입력 받음)
		for (int j = 0; j < n; j++) { // 현재 행에 대한 각 열
			if (s[j] == 'U') Umbrella.push_back(make_pair(i, j));
			else if (s[j] == 'E') {
				Umbrella.push_back(make_pair(i, j));
				End = make_pair(i, j); // 해당 위치를 End에 저장
			}
			else if (s[j] == 'S') Start = make_pair(i, j); // 해당 위치를 Start에 저장
		}
	}
	check_umbrella();
	if (ans == 1e9) cout << "-1\n";
	else cout << ans << "\n";
}