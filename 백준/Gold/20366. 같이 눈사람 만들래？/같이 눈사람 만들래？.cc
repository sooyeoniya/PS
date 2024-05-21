// 풀이 시간: 38m16s58
// 시간 복잡도: O(N^2logN)
// 공간 복잡도: O(N^2)

// 풀이 과정
// 1) 2개씩 선택하여 합친 눈사람 키를 배열에 삽입
// 2) 가능한 눈사람 키를 전부 삽입 후, 오름차순 정렬
// 3) 배열을 앞뒤로 두개씩 비교하면서 차이가 가장 적은 최솟값으로 갱신
// 오류: 추가 조건) 눈사람 중복 선택 불가 -> 각각의 인덱스도 함께 저장, 인덱스가 서로 단 하나도 중복되면 안됨

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, ans = 1e9;
int arr[600] = { 0, };

struct HEIGHT { int x, y, h; };
vector<HEIGHT> height;

bool CMP(HEIGHT A, HEIGHT B) {
	if (A.x == A.y) return A.y < B.y;
	if (A.h == B.h) return A.x < B.x;
	return A.h < B.h;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	for (int i = 0; i < N - 1; ++i) 
		for (int j = i + 1; j < N; ++j) 
			height.push_back({ i, j, arr[i] + arr[j] });

	sort(height.begin(), height.end(), CMP);

	for (int i = 0; i < height.size() - 1; ++i) {
		if (height[i + 1].x != height[i].x && 
			height[i + 1].x != height[i].y &&
			height[i + 1].y != height[i].y &&
			height[i + 1].y != height[i].x) 
			ans = min(ans, abs(height[i + 1].h - height[i].h));
	}
	cout << ans;
	return 0;
}