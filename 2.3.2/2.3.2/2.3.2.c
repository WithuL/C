#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void han(int n, char a, char b, char c) {
	if (n == 1) {
		printf("�����Ϊ%d�����Ӵ�%c�������ƶ���%c������\n", n, a, c);
	}
	else {
		han(n - 1, a, c, b);
		printf("�����Ϊ%d�����Ӵ�%c�������ƶ���%c������\n", n, a, c);
		han(n - 1, b, a, c);
	}
}
int main() {
	char a = 'A';
	char b = 'B';
	char c = 'C';
	int n;
	printf("�������ƶ����ӵĸ�����");
	scanf("%d", &n);
	han(n, a, b, c);
	return 0;
}