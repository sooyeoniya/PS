#include <stdio.h>
#include <string.h>
#include <math.h>
#include<algorithm>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979
#define min(a, b) (a > b ? b : a)
#define max 1000
int x[max] = { NULL };

int main(void)
{
	int n, temp = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (x[j] > x[j + 1]) {
				temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", x[i]);
	return 0;
}