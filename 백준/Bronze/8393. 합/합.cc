#include<stdio.h>

int main(void)
{
    int n, a = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		a += i;
	printf("%d", a);
	return 0;
}