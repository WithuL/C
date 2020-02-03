#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void han(int n, char a, char b, char c) {
	if (n == 1) {
		printf("将编号为%d的盘子从%c的柱子移动到%c的柱子\n", n, a, c);
	}
	else {
		han(n - 1, a, c, b);
		printf("将编号为%d的盘子从%c的柱子移动到%c的柱子\n", n, a, c);
		han(n - 1, b, a, c);
	}
}
int main() {
	char a = 'A';
	char b = 'B';
	char c = 'C';
	int n;
	printf("请输入移动盘子的个数：");
	scanf("%d", &n);
	han(n, a, b, c);
	return 0;
}