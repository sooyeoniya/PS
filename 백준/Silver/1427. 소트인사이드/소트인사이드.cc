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

int main(void)
{
	int n, cnt = 0;
	int a[100];
	scanf("%d", &n);

	while (n != 0)
	{
		a[cnt++] = n % 10;
		n = (n - n % 10) / 10;
	}

	for (int i = 0; i < cnt; i++)
		for (int j = 0; j < cnt - 1; j++)
			if (a[i] > a[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}

	for (int i = 0; i < cnt; i++)
		printf("%d", a[i]);

	return 0;
}