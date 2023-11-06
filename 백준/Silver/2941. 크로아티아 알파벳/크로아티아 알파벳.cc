#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	char a[101] = { NULL };
	scanf("%s", a);
	int sum = strlen(a);
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == '-' || a[i] == '=')
			sum--;
		if (a[i] == 'd' && a[i + 1] == 'z' && a[i + 2] == '=')
			sum--;
		if ((a[i] == 'l' || a[i] == 'n') && a[i + 1] == 'j')
			sum--;
	}
	printf("%d\n", sum);
	return 0;
}