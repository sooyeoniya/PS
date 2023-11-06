#include <stdio.h>
#include <string.h>
#include <math.h>
#include<algorithm>
#include <stdlib.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979
#define min(a, b) (a > b ? b : a)

//카운팅 정렬
#define max 10001
int x[max] = { NULL };

int main(void)
{
	int n, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		x[tmp]++;
	}
	for (int i = 0; i < max; i++) {
		if (x[i] != 0) {
			for (int j = 0; j < x[i]; j++)
				printf("%d\n", i);
		}
	}
	return 0;
}