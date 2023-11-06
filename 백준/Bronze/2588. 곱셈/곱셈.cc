#include<stdio.h>

int main(void)
{
	int A, B;
	scanf("%d", &A);
	scanf("%d", &B);
	printf("%d\n", A * (B % 10));
	printf("%d\n", (A * ((B % 100) - (B % 10))) / 10);
	printf("%d\n", (A * ((B % 1000) - (B % 100))) / 100);
	printf("%d", A * B);
	return 0;
}