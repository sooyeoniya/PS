#include <stdio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int x1, y1, x2, y2, r1, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		double d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		if (d == 0) { //좌표 같
			if (r1 == r2)
				printf("-1");
			else
				printf("0");
		}
		else { //좌표 다름
			if (d < (r2 - r1) * (r2 - r1)) printf("0"); //원 내부
			else if (d == (r2 - r1) * (r2 - r1)) printf("1");//내접
			else if (d > (r2 - r1) * (r2 - r1) && d < (r2 + r1) * (r2 + r1)) printf("2");//교점 2개
			else if (d == (r2 + r1) * (r2 + r1)) printf("1");//외접
			else if (d > (r2 + r1) * (r2 + r1)) printf("0");//만나지 X
		}
		printf("\n");
	}
	return 0;
}