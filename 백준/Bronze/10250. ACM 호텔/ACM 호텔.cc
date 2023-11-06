#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int H, W, N, a = 0, b = 0;
		scanf("%d %d %d", &H, &W, &N);
		if (N % H == 0)
		{
			a = H * 100;
			b = N / H;
		}
		else
		{
			a = (N % H) * 100;
			b = (N / H) + 1;
		}
		printf("%d\n", a + b);
	}
	return 0;
}