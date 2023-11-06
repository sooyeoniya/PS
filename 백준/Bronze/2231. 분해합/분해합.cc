#include <stdio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979

int main(void)
{
	int n, result = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int sum = 0;
		for (int j = 6; j >= 0; j--)
			sum += i / (int)pow(10, j) % 10;
		sum += i;
		if (sum == n) {
			result = i;
			break;
		}
	}
	printf("%d\n", result);
	return 0;
}