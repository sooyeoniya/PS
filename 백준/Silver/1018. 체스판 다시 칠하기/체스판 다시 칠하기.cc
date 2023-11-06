#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	//짝수번째 행의 짝수번째 열은 start와 같다
	//짝수번째 행의 홀수번째 열을 end와 같다
	//홀수번째 행의 짝수번째 열은 end와 같다
	//홀수번째 행의 홀수번째 열은 start와 같다
	//8 * 8로 나눠야함.
	//1. start가 W일때의 경우의 수 전부 검사
	//2. start가 B일때의 경우의 수 전부 검사
	//3. 더 작은 경우의 수를 출력
	int count = 0;
	int min1 = 1000000, min2 = 1000000;
	char start, end;
	char arr[51][51];
	int n, m;
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + 1; j++) {
			scanf("%c", &arr[i][j]);
		}
	}
	start = 'W'; end = 'B';
	for (int p = 8; p <= n; p++) {
		for (int o = 8; o <= m; o++) {
			count = 0;
			for (int i = p - 8; i < p; i++) {
				for (int j = o - 8; j < o; j++) {
					if (i % 2 == 0 && j % 2 == 0 && start != arr[i][j]) count++;
					else if (i % 2 == 0 && j % 2 == 1 && end != arr[i][j]) count++;
					else if (i % 2 == 1 && j % 2 == 0 && end != arr[i][j]) count++;
					else if (i % 2 == 1 && j % 2 == 1 && start != arr[i][j]) count++;
				}
			}
			if (count <= min1) min1 = count;
		}
	}
	start = 'B'; end = 'W';
	for (int p = 8; p <= n; p++) {
		for (int o = 8; o <= m; o++) {
			count = 0;
			//8x8 섹터를 돌면서 count++를 해줌.
			for (int i = p - 8; i < p; i++) {
				for (int j = o - 8; j < o; j++) {
					if (i % 2 == 0 && j % 2 == 0 && start != arr[i][j]) count++;
					else if (i % 2 == 0 && j % 2 == 1 && end != arr[i][j]) count++;
					else if (i % 2 == 1 && j % 2 == 0 && end != arr[i][j]) count++;
					else if (i % 2 == 1 && j % 2 == 1 && start != arr[i][j]) count++;
				}
			}
			if (count <= min2) min2 = count;
		}
	}
	if (min1 <= min2) printf("%d", min1);
	else printf("%d", min2);
	return 0;
}