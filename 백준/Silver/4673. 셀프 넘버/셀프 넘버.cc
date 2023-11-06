#include <stdio.h>
int result(int n);

int main(void)
{
	int a[10001], k;
	for (int i = 1; i < 10001; i++)
	{
		k = result(i);
		if (k < 10001)
			a[k] = 1;
	}
	for (int j = 1; j < 10001; j++)
	{
		if (a[j] != 1)
			printf("%d\n", j);
	}
}
int result(int n)
{
	int result = n;
	while (n > 0)
	{
		result += n % 10;
		n /= 10;
	}
	return result;
}