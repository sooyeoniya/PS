#include <stdio.h>
#include <string.h>
#include <math.h>
#include<algorithm>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979
#define min(a, b) (a > b ? b : a)

int main(void)
{
	int n, num = 665 , count = 0;
	scanf("%d", &n);
	while (count != n) {
		int tmp = ++num;
		while (tmp) {
			if (tmp % 1000 == 666) {
				count++;
				break;
			}
			tmp /= 10;
		}
	}
	printf("%d\n", num);
	return 0;
}