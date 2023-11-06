#include <stdio.h>

int main(void)
{
	int max = 0, idx = 0, a[26];
	char s[1000000];
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 'a' - 'A';
		a[s[i] - 'A']++;
	}
	for (int j = 0; j < 26; j++)
	{
		if (a[j] > max)
		{
			max = a[j];
			idx = j;
		}
		else if (a[j] == max)
			idx = -2;
	}
	printf("%c", idx + 'A');
	return 0;
}