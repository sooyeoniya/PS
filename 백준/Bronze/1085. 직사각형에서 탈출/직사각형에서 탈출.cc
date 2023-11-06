#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int x, y, w, h;
	int d = 0;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int a = x < (w - x) ? x : (w - x);
	int b = y < (h - y) ? y : (h - y);
	d = a < b ? a : b;
	printf("%d", d);
	return 0;
}