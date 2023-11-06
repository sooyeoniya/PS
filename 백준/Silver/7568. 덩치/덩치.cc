#include <stdio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979

int main(void)
{
	int n, xy[200][2] = { NULL }, result[200] = { NULL };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &xy[i][0], &xy[i][1]);
	for (int i = 0; i < n; i++) {
		int grade = 1;
		for (int j = 0; j < n; j++) {
			if (xy[i][0]<xy[j][0]&& xy[i][1] < xy[j][1]) grade++;
		}
		result[i] = grade;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", result[i]);
	return 0;
}