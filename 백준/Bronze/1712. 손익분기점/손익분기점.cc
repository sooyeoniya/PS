#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int A, B, C, sum, n = 1;
	scanf("%d %d %d", &A, &B, &C);
	if (B < C)
	{
		sum = A / (C - B);
		printf("%d\n", sum + 1);
	}
	else
		printf("-1\n");
	return 0;
}