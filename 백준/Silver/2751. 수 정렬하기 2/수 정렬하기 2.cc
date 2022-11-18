#include <stdio.h>
#include <string.h>
#include <math.h>
#include<algorithm>
#include <stdlib.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979
#define min(a, b) (a > b ? b : a)
#define max 1000001
int x[max] = { NULL };

int func(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	else if (*(int*)a > * (int*)b)
		return 1;
	else
		return 0;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);

	qsort(x, n, sizeof(int), func); //C언어 자체 내장 함수 퀵 정렬 qsort 이용

	for (int i = 0; i < n; i++)	printf("%d\n", x[i]);

	return 0;
}