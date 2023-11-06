#include <stdio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979
int f(int n)
{
	int a = 0, b = 1;
	if (n == 0) return a;
	else if (n == 1) return b;
	else return f(n - 1) + f(n - 2);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
	return 0;
}