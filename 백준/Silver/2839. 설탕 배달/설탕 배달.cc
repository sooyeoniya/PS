#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int n, i, j;
	scanf("%d", &n);

	for (i = n / 5; i >= 0; i--)
	{
		j = (n - 5 * i) / 3; // n이 18, i가 3일때 j는 1
		if ((5 * i + 3 * j) == n)
			break;
	}
	if (i == -1)
		printf("%d", i);
	else
		printf("%d", i + j);

	return 0;
}