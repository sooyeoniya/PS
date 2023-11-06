#include <stdio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979

int main(void)
{
	int n, m, a[101] = { NULL }, sum, result = 0, c1 = 0, c2 = 0, c3 = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n - 2; i++){
		c1 = a[i];
		for (int j = i + 1; j < n - 1; j++) {
			c2 = a[j];
			for (int o = j + 1; o < n; o++) {
				c3 = a[o];
				sum = c1 + c2 + c3;
				if (sum <= m) {
					if (result <= sum) result = sum;
				}
			}
		}
	}
	printf("%d\n", result);
	return 0;
}