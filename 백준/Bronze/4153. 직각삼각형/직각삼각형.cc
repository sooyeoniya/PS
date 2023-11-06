#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int a[3];
	while (1) {
		scanf("%d %d %d", &a[0], &a[1], &a[2]);

		if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0))
			break;

		for (int i = 0; i < 3; i++)
			a[i] = a[i] * a[i];

		if (a[0] == a[1] + a[2] || a[1] == a[0] + a[2] || a[2] == a[0] + a[1])
			printf("right\n");
		else
			printf("wrong\n");
	}
	
	return 0;
}