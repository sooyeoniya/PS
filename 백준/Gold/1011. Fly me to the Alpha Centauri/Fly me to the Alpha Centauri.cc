#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int T;
	long long x, y;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%ld %ld", &x, &y);
		long move = 0, turn = 0;
		for (long j = 0; j < y - x;)
		{
			move++;
			turn++;
			j += move;
			if (j >= y - x) break;
			turn++;
			j += move;
			if (j >= y - x) break;
		}
		printf("%ld\n", turn);
	}
	return 0;
}