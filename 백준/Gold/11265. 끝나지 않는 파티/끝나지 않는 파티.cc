#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> party_hall;

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
	party_hall = vector<vector<int>>(N);

	for (int i = 0; i < N; i++) {
		party_hall[i] = vector<int>(N);
		for (int j = 0; j < N; j++) {
			cin >> party_hall[i][j];
		}
	}
	floyd_warshall();
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		if (party_hall[A - 1][B - 1] <= C) cout << "Enjoy other party" << endl;
		else cout << "Stay here" << endl;
	}
}