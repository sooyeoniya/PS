#include<stdio.h>

int main(void)
{
	int n, t = 0;
	scanf("%d", &n);
	int a = n;
	while (1)
	{
		if (n >=0 && n < 10)
		{
			n = n * 10 + n;
		}
		else if (n >= 10)
		{
			n = n % 10 *10 + ((n - n % 10)/10 + n % 10) % 10;
		}
		t ++;
		if (a == n)
			break;
	}
	printf("%d", t);

	return 0;
}