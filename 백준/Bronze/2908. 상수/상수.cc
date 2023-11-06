#include <stdio.h>

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	a = a % 10 * 100 + (a % 100 - a % 10) + (a % 1000 - a % 100) / 100;
	b = b % 10 * 100 + (b % 100 - b % 10) + (b % 1000 - b % 100) / 100;
	if (a < b)
		printf("%d\n", b);
	else if (a > b)
		printf("%d\n", a);
	return 0;
}