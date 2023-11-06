#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[20];
	int t, r;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %s", &r, s);
		for (int j = 0; j < strlen(s) != '\0'; j++)
		{
			for (int o = 0; o < r; o++)
				printf("%c", s[j]);
		}
		printf("\n");
	}
	return 0;
}