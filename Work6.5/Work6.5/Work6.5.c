#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void pd(int a) {
	int i = 2;
	for (; i < a; i++) {
		if (a%i == 0) {
			printf("������������\n");
			break;
		}
	}
	if (i == a) {
		printf("����Ϊ����\n");
	}
}
int main() {
	int a = 0;
	scanf("%d", &a);
	pd(a);
	system("pause");
	return 0;
}