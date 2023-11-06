#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int x, y;
	int a[3][2];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &a[i][j]);
	int xx = a[0][0];
	int yy = a[0][1];
	if (a[0][0] == a[1][0])
		xx = a[2][0];
	else if (a[0][0] == a[2][0])
		xx = a[1][0];
	if (a[0][1] == a[1][1])
		yy = a[2][1];
	else if (a[0][1] == a[2][1])
		yy = a[1][1];
	printf("%d %d", xx, yy);
	return 0;
}