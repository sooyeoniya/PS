#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int x, y = 1, i;
	scanf("%d", &x);
	for (i = 1; x > y;)
		y += ++i;
	if (i % 2 == 0)
		printf("%d/%d", i - (y - x), 1 + (y - x));
	else
		printf("%d/%d", 1 + (y - x), i - (y - x));
	return 0;
}