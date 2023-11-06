#include <stdio.h>

int main(void)
{
	int c, c2, a[10000], sum, t;
	double avg, r;
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		sum = 0, t = 0;
		scanf("%d", &c2);
		for (int j = 0; j < c2; j++)
		{
			scanf("%d", &a[j]);
			sum += a[j];
		}
		avg = (double)sum / c2;
		for (int o = 0; o < c2; o++)
		{
			if (a[o] > avg)
				t++;
		}
		r = (double)t / c2 * 100;
		printf("%.3f%\n", r);
	}
	return 0;
}