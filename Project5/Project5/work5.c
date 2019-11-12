#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a;
	int b;
	int c;
	printf("请输入两个需要交换的数");
	scanf("%d%d", &a, &b);
	c = a;
	a = b;
	b = c;
	printf("交换后的数值为：%d  %d", a, b);
	system("pause");
	return 0;
}