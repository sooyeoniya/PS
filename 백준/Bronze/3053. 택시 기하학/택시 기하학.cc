#include <stdio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979

int main(void)
{
	int r;
	scanf("%d", &r);
	printf("%.6f\n%.6f", (double)r * r * PI, (double)r * r * 2);
	return 0;
}