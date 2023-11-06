#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	if (a == v)
		printf("1\n");
	else
	{
		if ((v - a) % (a - b) == 0)
			printf("%d\n", (v - a) / (a - b) + 1);
		else
			printf("%d\n", (v - a) / (a - b) + 2);
	}
	return 0;
}