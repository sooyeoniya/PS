#include <stdio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979

int main(void)
{
	int n, j;
	while (1)
	{
		int sum = 0, a[246912] = { NULL };
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 2; i * i < 246912; i++) {
			if (a[i] == 0) {
				for (int j = i * i; j < 246912; j += i)
					a[j] = 1;
			}
		}
		for (int i = n + 1; i <= 2 * n; i++) {
			if (a[i] == 0)
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}