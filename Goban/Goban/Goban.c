#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 15
#define MAX_COL 15
#include<stdio.h>
#include<stdlib.h>
//��Ϸ����
//���̴�СΪ15X15
//�˺ͻ�����˭���������������һ������Ϊ˭Ӯ
//�˵�����Ϊ'X',����Ϊ'O' ������
void Menu() {
	printf("��ӭ������������Ϸ��\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.�˳���Ϸ\n");
	printf("����������ѡ��:\n");
}

char Init(char chessboard[MAX_ROW][MAX_COL]){
	//�����̽��г�ʼ��
	memset(chessboard, ' ', MAX_ROW*MAX_COL);
}

//��ӡ���̣���һ������ȫΪ�ո�
void Print(char chessboard[MAX_ROW][MAX_COL]) {
	int row,col;
	for (row = 0; row < MAX_ROW; row++) {
		for (col = 0; col < MAX_COL; col++) {
			printf("%c ", chessboard[row][col]);
		}
		printf("\n");
	}
}

//�������
void PlayerMove(char chessboard[MAX_ROW][MAX_COL]) {
	int row, col;
	printf("����������λ��\n");
	scanf("%d %d", &row, &col);
	//�����жϣ����λ��Ϊ' '������Խ�������
	if (chessboard[MAX_ROW][MAX_COL] == ' ') {
		chessboard[row][col] = 'X';
	}
}
void Game(char chessboard[MAX_ROW][MAX_COL]) {
	//��Ϸ���裻
	//1.��������������
	Init(chessboard[MAX_ROW][MAX_COL]);
	while (1) {
		//2.��ӡ����(�״�Ϊ������)
		Print(chessboard[MAX_ROW][MAX_COL]);
		//3.������ӣ���ʾ�������)
		PlayerMove(chessboard[MAX_ROW][MAX_COL]);
		//4.�����Ϸ�Ƿ����
		Check(chessboard[MAX_ROW][MAX_COL]);
		//5.��������
		ComputerMove(chessboard[MAX_ROW][MAX_COL]);
		//6.�����Ϸ�Ƿ����
		Check(chessboard[MAX_ROW][MAX_COL]);
		//7.���δ��������2

	}
}

int main() {
	while (1) {
		Menu();
		int choice = 0;
		scanf("%d", &choice);
		if (choice == 1) {
			char cheesboard[MAX_ROW][MAX_COL];
			Game(cheesboard);
			break;
		}
		else if (choice == 0) {
			break;
		}
		else {
			printf("����������������������!\n");
		}
	}
	system("pause");
	return 0;
}