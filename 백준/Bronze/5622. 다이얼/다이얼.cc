#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	char a[16] = { NULL };
	int dial[] = { 3, 3, 3, 4, 4, 4, 5, 5 ,5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
	int sum = 0;
	scanf("%s", a);
	for (int i = 0; i < strlen(a); i++)
		sum += dial[a[i] - 65];
	printf("%d\n", sum);
	return 0;
}