#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int T, k, n;
	scanf("%d", &T);
	int a[15][15] = { NULL };
	for (int i = 1; i < 15; i++)
	{
		a[0][i] = i;
		a[i][1] = 1;
	}
	for (int i = 1; i < 15; i++)
		for (int j = 1; j < 15; j++)
			a[i][j] = a[i][j - 1] + a[i - 1][j];
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", a[k][n]);
	}
	return 0;
}