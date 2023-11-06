#include<stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int j = n - 1; j >= 0; j--)
	{
		for (int i = 0; i < j; i++)
			printf(" ");
		for (int o = 0; o < n - j; o++)
			printf("*");
		printf("\n");
	}
	return 0;
}