#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int password = 987654321;
	int a,i;
	for (i = 1; i < 4; i++) {
		printf("����������:\n");
		scanf("%d", &a);
		switch (a) {
		case 987654321:
			printf("��½�ɹ���\n");
			break;
		default:
			printf("�������\n");
			break;
		}
		if (i == 3) {
			printf("��������������Σ�ϵͳ�Զ��˳�\n");
		}
		if (a == 987654321) {
			system("pause");
			return 0;
		}
	}
	system("pause");
	return 0;
}