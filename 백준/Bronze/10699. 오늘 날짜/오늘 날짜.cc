#include <iostream>
#include <ctime>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);
    cout << t->tm_year + 1900 << "-";
    cout.width(2); cout.fill('0');
    cout<< t->tm_mon + 1 << "-";
    cout.width(2); cout.fill('0');
    cout << t->tm_mday;
    return 0;
}