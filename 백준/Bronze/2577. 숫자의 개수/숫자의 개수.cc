#include <stdio.h>

int main(void)
{
	int A, B, C, n, k = 0, a[10] = {NULL};
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	n = A * B * C;
	while (n != 0)
	{
		k = n % 10;
		n /= 10;
		a[k]++;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}

	return 0;
}