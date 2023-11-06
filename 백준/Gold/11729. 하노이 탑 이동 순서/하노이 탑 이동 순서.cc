#include <stdio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979
int cal = 0;
int ha(int a, int b, int c, int n)
{
	if (n == 1) cal++;
	else {
		ha(a, c, b, n - 1);
		cal++;
		ha(b, a, c, n - 1);
	}
	return cal; //int형 변환
}
void hanoi(int a, int b, int c, int n) //하노이탑 함수 진행과정
{
	if (n == 1)
		printf("%d %d\n", a, c);
	else {
		hanoi(a, c, b, n - 1); // b, c change
		printf("%d %d\n", a, c);
		hanoi(b, a, c, n - 1); // a, b change
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", ha(1, 2, 3, n));
	hanoi(1, 2, 3, n);
	return 0;
}