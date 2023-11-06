#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int N, layer = 1, sum = 1;
	scanf("%d", &N);
	while (sum < N)
		sum = sum + 6 * layer++;
	printf("%d\n", layer);
	return 0;
}