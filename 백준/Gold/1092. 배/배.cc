#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, cnt = 0;
vector<int> crane;
vector<int> box;

void greedy() {
    // 박스가 모두 배에 실릴 때까지 while 루프 동작
    while (!box.empty()) {
        for (int i = 0; i < crane.size(); ++i) {
            for (int j = 0; j < box.size(); ++j) {
                if (crane[i] >= box[j]) { 
                    // 해당 크레인이 들 수 있는 가장 큰 무게의 박스를 꺼냄
                    box.erase(box.begin() + j);
                    break; 
                }
            }
        }
        // 모든 크레인은 동시에 움직이므로 for문을 전부 돌고난 후 1분 추가
        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N; // 크레인 수
    crane = vector<int>(N + 1, 0); // 각 크레인 무게 제한
    for (int i = 0; i < N; ++i) cin >> crane[i];

    cin >> M; // 박스 수
    box = vector<int>(M + 1, 0); // 각 박스 무게
    for (int i = 0; i < M; ++i) cin >> box[i];

    // 내림차순 정렬
    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());
    
    // 
    if (crane[0] < box[0]) {
        printf("-1\n");
        return 0;
    }

    greedy();
    cout << cnt;
    return 0;
}