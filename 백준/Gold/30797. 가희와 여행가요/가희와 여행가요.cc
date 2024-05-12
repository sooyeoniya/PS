#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct EDGE {
    int From, To;
    long long Cost, Time;
};

int N, Q, From, To;
long long Cost, Time, Answer_Time = 0, Answer_Cost = 0;
vector<EDGE> Edge;
int Parent[200001];

bool Comp(EDGE A, EDGE B) {
    if (A.Cost == B.Cost) {
        return (A.Time < B.Time);
    }
    return (A.Cost < B.Cost);
}

int find_Parent(int X) {
    if (Parent[X] == X) return X;
    return Parent[X] = find_Parent(Parent[X]);
}

void union_Group(int X, int Y) {
    int ParentX = find_Parent(X);
    int ParentY = find_Parent(Y);
    if (ParentX < ParentY) {
        Parent[ParentY] = ParentX;
    }
    else {
        Parent[ParentX] = ParentY;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 200001; ++i) Parent[i] = i;
    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> From >> To >> Cost >> Time;
        Edge.push_back({ From, To, Cost, Time });
    }
    sort(Edge.begin(), Edge.end(), Comp);

    for (int i = 0; i < (int)Edge.size(); i++) {
        if (find_Parent(Edge[i].From) != find_Parent(Edge[i].To)) {
            union_Group(Edge[i].From, Edge[i].To);
            Answer_Cost += Edge[i].Cost;
            Answer_Time = max(Answer_Time, Edge[i].Time);
        }
    }

    for (int i = 2; i <= N; i++) {
        if (find_Parent(i) != 1) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << Answer_Time << " " << Answer_Cost << "\n";
    return 0;
}