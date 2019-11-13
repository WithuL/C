#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void menu() {
	printf("************************************************\n");
	printf("*****************输入1开始游戏*******************\n");
	printf("*****************输入0退出游戏*******************\n");
	printf("************************************************\n");

}

void game() {
	int random_num = rand() % 101;
	int a = 0;
	while (1) {
		printf("请输入猜测的数字:\n");
		scanf("%d", &a);
		if (a > random_num){
			printf("猜大了\n");
		}
		else if (a < random_num) {
			printf("猜小了\n");
		}
		else {
			printf("猜对了\n");
			break;
		}
	}
}
int main() {
	int a = 0;
	srand((unsigned)time(NULL));
	do{
		menu();
		scanf("%d", &a);

		switch (a) {
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("您的输入有误，请重新输入！\n");
			break;
		}
	} while (a);
	return 0;
}