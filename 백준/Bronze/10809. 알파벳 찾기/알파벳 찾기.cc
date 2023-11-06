#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[100];
	int a[26];
	scanf("%s", s);
	for (int i = 0; i < 26; i++)
		a[i] = -1;
	for (int j = 0; j < 26; j++)
	{
		for (int i = 0; i < strlen(s); i++)
		{
			if (s[i] == 97 + j)
			{
				a[s[i]-'a'] = i;
				break;
			}
		}
	}
	for (int o = 0; o < 26; o++)
		printf("%d ", a[o]);
	return 0;
}