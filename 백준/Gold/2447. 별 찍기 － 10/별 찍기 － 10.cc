#include <stdio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979

char a[2188][2188] = { NULL };

void star(int n, int num) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i % num == num / 3 && j % num == num / 3)
				for (int o = 0; o < num / 3; o++)
					for (int k = 0; k < num / 3; k++)
						a[i + o][j + k] = 1;

	if (num < n) {
		num *= 3;
		star(n, num);
	}
}

int main(void)
{
	int n, num = 3;
	scanf("%d", &n);
	star(n, num);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}