#include <stdio.h>
#include <string.h>
#include <math.h>
#include<algorithm>
#include <stdlib.h> //qsort
#include <utility> //pair 함수 호출
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979
#define min(a, b) (a > b ? b : a)

pair<int, int> location[100001];

bool compare(pair<int, int> a, pair<int, int> b);

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &location[i].first, &location[i].second);
	
	sort(location, location + n, compare); //sort는 기본적으로 오름차순 정렬

	for (int i = 0; i < n; i++)
		printf("%d %d\n", location[i].first, location[i].second);
	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second; //sort '<' 오름차순, '>' 내림차순
}