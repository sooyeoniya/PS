#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) ((a)>(b)?(a):(b))

int main(void)
{
	char a[10002], b[10002];
	int sum[10003] = { NULL };
	int flag, aindex, bindex, temp;

	scanf("%s %s", a, b);
	aindex = strlen(a) - 1;
	bindex = strlen(b) - 1;
	if (strlen(a) > strlen(b)) flag = 1;
	else if (strlen(a) < strlen(b)) flag = 2;
	else flag = -1;

	if (flag == 1)
	{
		for (int i = bindex; i >= 0; i--)
			b[aindex - bindex + i] = b[i];
		for (int i = 0; i < aindex - bindex; i++)
			b[i] = '0';
	}
	else if (flag == 2)
	{
		for (int i = aindex; i >= 0; i--)
			a[bindex - aindex + i] = a[i];
		for (int i = 0; i < bindex - aindex; i++)
			a[i] = '0';
	}

	for (int i = max(strlen(a), strlen(b)) - 1; i >= 0; i--)
	{
		temp = (a[i] - '0') + (b[i] - '0');
		if (sum[i + 1] + temp >= 10)
		{
			sum[i + 1] = (sum[i + 1] + temp) % 10;
			sum[i]++;
		}
		else
		{
			sum[i + 1] += temp % 10;
			sum[i] += temp / 10;
		}
	}

	if (sum[0] == 0)
		for (int i = 1; i <= max(strlen(a), strlen(b)); i++)
			printf("%d", sum[i]);
	else
		for (int i = 0; i <= max(strlen(a), strlen(b)); i++)
			printf("%d", sum[i]);

	return 0;
}