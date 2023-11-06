#include <stdio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979

int main(void)
{
	int n, sum = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		sum *= i;
	printf("%d\n", sum);
	return 0;
}