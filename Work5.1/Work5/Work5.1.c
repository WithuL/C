#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void menu() {
	printf("************************************************\n");
	printf("*****************����1��ʼ��Ϸ*******************\n");
	printf("*****************����0�˳���Ϸ*******************\n");
	printf("************************************************\n");

}

void game() {
	int random_num = rand() % 101;
	int a = 0;
	while (1) {
		printf("������²������:\n");
		scanf("%d", &a);
		if (a > random_num){
			printf("�´���\n");
		}
		else if (a < random_num) {
			printf("��С��\n");
		}
		else {
			printf("�¶���\n");
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
			printf("���������������������룡\n");
			break;
		}
	} while (a);
	return 0;
}