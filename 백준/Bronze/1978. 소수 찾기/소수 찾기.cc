#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int n, t = 0;
	int a[101] = { NULL };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 1)
			t++;
		for (int j = 2; j < a[i] - 1; j++)
		{
			if (a[i] % j == 0)
			{
				t++;
				break;
			}
		}
	}
	printf("%d\n", n - t);
	return 0;
}