#include <stdio.h>

int main(void)
{
	int n = 0, max = 0, a[10];
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &a[i]);
		if (max < a[i])
		{
			max = a[i];
			n = i + 1;
		}
	}
	printf("%d\n%d", max, n);
	return 0;
}