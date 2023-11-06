#include<stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int j = 1; j <= n; j++)
	{
		for (int i = 0; i < j; i++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}