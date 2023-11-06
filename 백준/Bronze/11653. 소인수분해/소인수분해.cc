#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int n;
	scanf("%d", &n);
	if (n > 1)
	{
		for (int i = 2; i <= n; i++)
		{
			while (1)
			{
				if (n % i == 0)
				{
					printf("%d\n", i);
					n /= i;
				}
				else
					break;
			}
		}
	}
	return 0;
}