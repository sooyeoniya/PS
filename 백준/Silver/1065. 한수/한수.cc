#include <stdio.h>

int main(void)
{
	int a, result = 0;
	int one = 0, ten = 0, hun = 0;
	int gap_oneten = 0;
	int gap_tenhun = 0;
	scanf("%d", &a);
	if (a < 100)
		result = a;
	else
	{
		result = 99;
		for (int i = 100; i <= a; i++)
		{
			hun = i / 100;
			ten = (i - (100 * hun)) / 10;
			one = i % 10;
			gap_oneten = ten - one;
			gap_tenhun = hun - ten;

			if (gap_oneten == gap_tenhun)
				result++;
		}
	}
	printf("%d\n", result);
}