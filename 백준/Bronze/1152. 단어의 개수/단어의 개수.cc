#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	char a[1000001];
	int i = 0, sum = 0;
	fgets(a, sizeof(a), stdin);
	if (a[0] == ' ')
		sum--;

		do {
			if (a[i] == ' ' && a[i + 1] != '\n')
				sum++;
			i++;
		} while (a[i] != '\0');
			sum++;
			printf("%d", sum);
	return 0;
}