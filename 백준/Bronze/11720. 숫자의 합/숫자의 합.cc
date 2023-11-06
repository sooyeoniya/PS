#include <stdio.h>
//#define CRT_SECURE_NO_WARNINGS

int main(void)
{
	int n, sum = 0;
	char a[100] = { NULL };
	scanf("%d", &n);
	scanf("%s", a);
	for (int i = 0; i < n; i++)
	{
		sum += a[i] - 48;
	}
	printf("%d\n", sum);
	return 0;
}