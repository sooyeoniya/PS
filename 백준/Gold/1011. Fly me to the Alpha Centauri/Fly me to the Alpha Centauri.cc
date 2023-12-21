#include <stdio.h>

int main() {
	int t;
	long x, y;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%ld %ld", &x, &y);
		long term = 0, turn = 0;
		for (long num = 0; num < y - x;) {
			term++;

			turn++;num += term;
			if (num >= y - x) break;

			turn++;num += term;
			if (num >= y - x) break;
		}
		printf("%ld\n", turn);
	}
	return 0;
}