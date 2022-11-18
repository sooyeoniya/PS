#include <stdio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979

int isPrime(int input)
{
	int tmp;
	if (input == 2)
		return 1;
	else if (input % 2 == 0 || input == 1)
		return 0;
	else
	{
		tmp = 1;
		for (int j = 3; j * j < input + 1; j = j + 2) {
			if (input % j == 0) {
				tmp = 0;
				return 0;
			}
		}
		if (tmp == 1) {
			return 1;
		}
	}
}
int main(void)
{
	int T;
	scanf("%d", &T);
	int n;
	int tmp, tmp1, tmp2;
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		tmp = n / 2;
		tmp1 = tmp2 = tmp;
		for (int j = 0; j < tmp; j++) {
			if (isPrime(tmp1) == 1 && isPrime(tmp2) == 1) {
				printf("%d %d\n", tmp1, tmp2);
				break;
			}
			else {
				tmp1 = tmp1 - 1;
				tmp2 = tmp2 + 1;
			}
		}
	}
	return 0;
}