#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int M, N, t = 0, sum = 0, min = 10001;
	scanf("%d", &M);
	scanf("%d", &N);
	for (int i = M; i <= N; i++)
	{
		t = 0;
		if (i == 1)
			t++;
		for (int j = 2; j < i - 1; j++)
		{
			if (i % j == 0)
			{
				t++;
				break;
			}
		}
		if (t == 0)
		{
			sum += i;
			if (i < min)
				min = i;
		}
	}
	if (min == 10001)
		printf("-1");
	else
		printf("%d\n%d\n", sum, min);
	return 0;
}