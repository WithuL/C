#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int password = 987654321;
	int a,i;
	for (i = 1; i < 4; i++) {
		printf("请输入密码:\n");
		scanf("%d", &a);
		switch (a) {
		case 987654321:
			printf("登陆成功！\n");
			break;
		default:
			printf("密码错误！\n");
			break;
		}
		if (i == 3) {
			printf("您已输入错误三次，系统自动退出\n");
		}
		if (a == 987654321) {
			system("pause");
			return 0;
		}
	}
	system("pause");
	return 0;
}