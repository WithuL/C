#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i, j, a;
	printf("ÇëÊäÈëÊı×Ö\n");
	scanf("%d", &a);
	for (i = 1; i <= a; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d*%d=%d  ", i, j, i*j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}