#include<stdio.h>

int main(void)
{
    int h, m;
	scanf("%d %d", &h, &m);
	if (0 <= h && m >= 45)
		printf("%d %d", h, m - 45);
	else if (0 < h && (m >= 0 && m < 45))
		printf("%d %d", h - 1, 60 - (45 - m));
	else if (h == 0 && (m >= 0 && m < 45))
		printf("%d %d", h + 23, 60 - (45 - m));
	return 0;
}