/**
* 풀이 시간: 30:46
* 시간 복잡도: O(N^2+M+N^3) = O(N^3) // floyd_warshall()의 O(N^3)
* 공간 복잡도: O(N^2) // party_hall의 공간 복잡도
* 참고 자료: https://chanhuiseok.github.io/posts/algo-50/
*/
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> party_hall;

// 중간 노드 k를 거쳐서 가는 이동 시간과 현재 이동 시간 비교하여 더 작은 값으로 갱신
void floyd_warshall() {
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				party_hall[i][j] = min(party_hall[i][j], party_hall[i][k] + party_hall[k][j]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	party_hall = vector<vector<int>>(N); // 파티장 2차원 벡터

	for (int i = 0; i < N; i++) { // 파티장 이동 시간 초기화
		party_hall[i] = vector<int>(N);
		for (int j = 0; j < N; j++) {
			cin >> party_hall[i][j];
		}
	}

	floyd_warshall(); // 플로이드-워셜 알고리즘

	// A에서 B로 이동하는 시간이 시간 C를 넘지 않는지 확인
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		if (party_hall[A - 1][B - 1] <= C) cout << "Enjoy other party" << endl;
		else cout << "Stay here" << endl;
	}
}
