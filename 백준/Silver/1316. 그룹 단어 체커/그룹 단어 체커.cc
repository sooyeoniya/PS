#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
int select(char a[], int len);

int main(void)
{
	char a[100];
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", a);
		sum += select(a, strlen(a));
	}
	printf("%d\n", sum);
	return 0;
}

int select(char a[], int len)
{
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (a[i] == a[j])
			{
				k = j - i;
				if (k > 1)
					if (a[j - 1] != a[j])
						return 0;
			}
		}
	}
	return 1;
}