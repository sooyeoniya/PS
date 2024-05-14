// 풀이 시간: 1h55m24s86
// 참고 자료
// https://gusdnr69.tistory.com/33
// https://velog.io/@soosungp33/BOJ-8980%EB%B2%88-%ED%83%9D%EB%B0%B0
#include <iostream>
#include <algorithm>
using namespace std;

struct INFO { int send, recieve, cnt; };

INFO arr[10001];
int N, C, M, ans = 0;
int capacity[10001] = { 0, };

bool cmp (INFO A, INFO B) {
    if (A.recieve == B.recieve) // 2. 받는 마을이 같다면 보내는 마을로 오름차순 정렬
        return A.send < B.send;
    return A.recieve < B.recieve; // 1. 받는 마을 먼저 오름차순 정렬
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> C >> M;
    for (int i = 0; i < M; ++i)
        cin >> arr[i].send >> arr[i].recieve >> arr[i].cnt;

    sort(arr, arr + M, cmp); // 정렬

    for (int i = 0; i < M; ++i) {
        int maxCnt = 0;
        for (int j = arr[i].send; j < arr[i].recieve; ++j)
            maxCnt = max(capacity[j], maxCnt); // 현재 마을에서 트럭에 실린 가장 큰 값 반환
        
        int val = min(arr[i].cnt, C - maxCnt); // 트럭에 실릴 값
        ans += val;

        for (int j = arr[i].send; j < arr[i].recieve; ++j)
            capacity[j] += val; // 트럭에 싣기
    }

    cout << ans;
    return 0;
}