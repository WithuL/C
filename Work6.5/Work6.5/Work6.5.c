#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void pd(int a) {
	int i = 2;
	for (; i < a; i++) {
		if (a%i == 0) {
			printf("此数不是素数\n");
			break;
		}
	}
	if (i == a) {
		printf("此数为素数\n");
	}
}
int main() {
	int a = 0;
	scanf("%d", &a);
	pd(a);
	system("pause");
	return 0;
}