#include <iostream>
#include <deque>
using namespace std;
int num = 0, dir = 0;
deque<int> w1, w2, w3, w4; // 12시 방향부터 시계방향 순서대로 삽입

void forward(int w) { // 시계 회전
    switch (w) {
        case 0: // w1
            w1.push_front(w1.back());
            w1.pop_back();
            break;
        case 1: // w2
            w2.push_front(w2.back());
            w2.pop_back();
            break;
        case 2: // w3
            w3.push_front(w3.back());
            w3.pop_back();
            break;
        case 3: // w4
            w4.push_front(w4.back());
            w4.pop_back();
            break;
    }
}

void backward(int w) { // 반시계 회전
    switch (w) {
        case 0: // w1
            w1.push_back(w1.front());
            w1.pop_front();
            break;
        case 1: // w2
            w2.push_back(w2.front());
            w2.pop_front();
            break;
        case 2: // w3
            w3.push_back(w3.front());
            w3.pop_front();
            break;
        case 3: // w4
            w4.push_back(w4.front());
            w4.pop_front();
            break;
    }
}

void rotateWheel() {
    // 톱니는 전부 동시에 회전하기 때문에 각 톱니의 좌우 값을 따로 저장해줌
    // forward, backward 함수에 의해 값이 변동되기 때문
    int r1 = w1[2], l1 = w1[6], r2 = w2[2], l2 = w2[6];
    int r3 = w3[2], l3 = w3[6], r4 = w4[2], l4 = w4[6];
    if (dir == 1) { // 시계
        switch (num) {
            case 1: // w1
                forward(0); // w1 시계
                if (r1 != l2) {
                    backward(1); // w2 반시계
                    if (r2 != l3) {
                        forward(2); // w3 시계
                        if (r3 != l4)
                            backward(3); // w4 반시계
                    }
                }
                break;
            case 2: // w2
                forward(1); // w2 시계
                if (r1 != l2) backward(0); // w1 반시계
                if (r2 != l3) {
                    backward(2); // w3 반시계
                    if (r3 != l4) forward(3); // w4 시계
                }
                break;
            case 3: // w3
                forward(2); // w3 시계
                if (r3 != l4) backward(3); // w4 반시계
                if (r2 != l3) {
                    backward(1); // w2 반시계
                    if (r1 != l2) forward(0); // w1 시계
                }
                break;
            case 4: // w4
                forward(3); // w4 시계
                if (r3 != l4) {
                    backward(2); // w3 반시계
                    if (r2 != l3) {
                        forward(1); // w2 시계
                        if (r1 != l2)
                            backward(0); // w1 반시계
                    }
                }
                break;
        }
    }
    else { // 반시계
        switch (num) {
            case 1:
                backward(0); // w1 반시계
                if (r1 != l2) {
                    forward(1); // w2 시계
                    if (r2 != l3) {
                        backward(2); // w3 반시계
                        if (r3 != l4)
                            forward(3); // w4 시계
                    }
                }
                break;
            case 2:
                backward(1); // w2 반시계
                if (r1 != l2) forward(0); // w1 시계
                if (r2 != l3) {
                    forward(2); // w3 시계
                    if (r3 != l4) backward(3); // w4 반시계
                }
                break;
            case 3:
                backward(2); // w3 반시계
                if (r3 != l4) forward(3); // w4 시계
                if (r2 != l3) {
                    forward(1); // w2 시계
                    if (r1 != l2) backward(0); // w1 반시계
                }
                break;
            case 4:
                backward(3); // w4 반시계
                if (r3 != l4) {
                    forward(2); // w3 시계
                    if (r2 != l3) {
                        backward(1); // w2 반시계
                        if (r1 != l2)
                            forward(0); // w1 시계
                    }
                }
                break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 4; ++i) { // 톱니바퀴 상태 삽입
        string str; cin >> str;
        for (int j = 0; j < str.size(); ++j) {
            int x = str[j] - '0';
            switch (i) {
                case 0: w1.push_back(x); break;
                case 1: w2.push_back(x); break;
                case 2: w3.push_back(x); break;
                case 3: w4.push_back(x); break;
            }
        }
    }
    int K; cin >> K;
    while (K--) { // 이동 횟수
        cin >> num >> dir;
        rotateWheel();
    }
    int score = 0; // S극일 때만 점수 추가
    if (w1.front() == 1) score += 1;
    if (w2.front() == 1) score += 2;
    if (w3.front() == 1) score += 4;
    if (w4.front() == 1) score += 8;
    cout << score;
    return 0;
}