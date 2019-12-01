#include <stdio.h>
#include <stdlib.h>
int main() {
	int a[5][5] = { 0 };
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < i; j++) {
			if (i == 1) {
				printf("%4d\n", a[1][1] = 1);
			}
			else {
				if ((j == 1) || (i == j)) {
					printf("%4d", a[i][j] = 1);
				}
				else {
					printf("%4d", a[i][j] = a[i - 1][j - 1] + a[i - 1][j]);
				}
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}