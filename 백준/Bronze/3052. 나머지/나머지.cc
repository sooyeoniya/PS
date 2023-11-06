#include <stdio.h>

int main(void)
{
	int a[20] = { NULL }, b[50] = { NULL };
	int n = 0;
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (int j = 0; j < 10; j++)
	{
		int k = a[j] % 42;
		if (b[k] == NULL)
		{
			b[k]++;
			n++;
		}
	}
	printf("%d", n);
	return 0;
}