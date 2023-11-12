// 풀이 시간: 1:36:56
// 시간 복잡도: O(mlogn) - 이진 탐색(O(logN)-> 이때 N은 탐색 범위의 크기)을 m번 수행
// 공간 복잡도: O(n) - name과 power 배열의 크기가 각각 n
// 참고 코드: https://cjh5414.github.io/binary-search/
//            https://leeeegun.tistory.com/4
 
#include <iostream>
using namespace std;

int n, m; // 칭호 개수 n, 캐릭터의 개수 m
string name[100000]; // 칭호를 저장하는 배열
int power[100000]; // 칭호에 대한 전투력을 저장하는 배열
// name과 power는 서로 같은 인덱스 값에 서로 연관된 값 저장

int binary_search(int x) { // 이진 탐색 활용, 반환값은 캐릭터 전투력의 위치(name, power의 인덱스 값을 의미)
	int left = 0, right = n - 1, mid = 0; // left를 0, right를 칭호 개수 n보다 1 작은 값으로 설정
	while (left <= right) { 
		mid = (left + right) / 2; // 중간값 설정
		// 만약 캐릭터의 전투력 x가 배열 power의 중간값 인덱스에 해당하는 값보다 작으면 right를 중간값보다 1 작은 값으로 설정
		if (x <= power[mid]) right = mid - 1;
		// 그렇지 않을 경우, 배열 power의 중간값 인덱스에 해당하는 값보다 캐릭터의 전투력이 큰 것이므로 left를 중간값보다 1 큰 값으로 설정
		else left = mid + 1;
	}
	// 만약 캐릭터 전투력 x가 현재 배열 power의 중간값 인덱스에 해당하는 값보다 클 경우
	// e.g. 현재 mid가 0이고, x가 10001일 때, x가 power[0]인 10000보다 크므로 mid 값에 1을 더해주어야 함
	if (x > power[mid]) return mid + 1; 
	else return mid; // 그 외의 경우에는 그냥 mid 값 출력
}

int main(void) {
	// C++ 에서는 C의 표준 입출력을 혼용하는 것을 허용
  // C의 표준 입출력의 동기화를 꺼줌으로써 속도 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	// 각 칭호별 전투력 저장
	for (int i = 0; i < n; i++) cin >> name[i] >> power[i];

	int x; // 캐릭터의 전투력
	for (int i = 0; i < m; i++) {
		cin >> x;
		cout << name[binary_search(x)] << "\n"; // 캐릭터 전투력의 인덱스에 대한 칭호 출력
	}
}
