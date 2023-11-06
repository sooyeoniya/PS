#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int M, N, a[1000001] = { NULL };
	a[0] = 1, a[1] = 1;
	for (int j = 2; j < 1000001 / j; j++)
	{
		if (a[j] == 1)
			continue;
		for (int i = j * j; i < 1000001; i += j)
			if (i % j == 0)
				a[i] = 1;
	}
	scanf("%d %d", &M, &N);
	for (int i = M; i <= N; i++)
		if (a[i] == 0)
			printf("%d\n", i);
	
	return 0;
}