//��Ϸ����
//1.����һ���ַ��Ͷ�ά���飬x��ʾ������ӣ�o��ʾ�������ӣ��հ�' '��ʾ����ط�δ����
//2.��Ϸ��ʼ���ȴ�ӡһ�����̣��հ����̣�
//3.��ʾ�������
//4.�����Ϸ�Ƿ����
//5.��������
//6.�����Ϸ�Ƿ����
//���δ�����ͷ���2
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 3
#define MAX_COL 3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int Menu() {
	printf("===========================\n");
	printf("========��ӭ����������=======\n");
	printf("========����1��ʼ��Ϸ========\n");
	printf("========����0�˳���Ϸ========\n");
	printf("===========================\n");
	printf("����������ѡ��\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}

void Init(char cheseBoard[MAX_ROW][MAX_COL]) {
	srand((unsigned)time(0));
	memset(cheseBoard, ' ', MAX_ROW*MAX_COL);
}

void Print(char chessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		printf("+++++++\n");//��ӡ�ָ���
		printf("|%c|%c|%c|", chessBoard[row][0], chessBoard[row][1], chessBoard[row][2]);//��ӡÿ��Ԫ��
		printf("\n");
	}
	printf("+++++++\n");
}

int IsFull(char chessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

void PlayerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("�ֵ��������\n");
	while (1) {
		printf("��������Ҫ���ӵ�����(��)(��)\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row<0||row>=MAX_ROW||col<0||col>=MAX_COL) {
			printf("���������������������룡\n");
			continue;
		}
		if (chessBoard[row][col] != ' ') {
			printf("���λ���Ѿ�������\n");
			continue;
		}
		chessBoard[row][col] = 'X';
		break;
	}
}

void ComputerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("�ֵ�����������\n");
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' ') {
			continue;
		}
		chessBoard[row][col] = 'O';
		break;
	}
}

char Check(char chessBoard[MAX_ROW][MAX_COL]) {
	//�������������
	//1.���Ӯ     ����X
	//2.����Ӯ     ����O
	//3.����       ����Q
	//4.δ�ֳ�ʤ��  'O'

	//���������û������������ͬ��
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '&&
			chessBoard[row][0] == chessBoard[row][1] &&
			chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	//���������û������������ͬ��
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '&&
			chessBoard[0][col] == chessBoard[1][col] &&
			chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	//���Խ�������û����ͬ��
	if (chessBoard[0][0] != ' '&&
		chessBoard[0][0] == chessBoard[1][1] &&
		chessBoard[0][0] == chessBoard[2][2]) {
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '&&
		chessBoard[0][2] == chessBoard[1][1] &&
		chessBoard[0][2] == chessBoard[2][0]) {
		return chessBoard[0][2];
	}
	//����Ƿ�Ϊ����  ����������δ��ʤ��
	if (IsFull(chessBoard)) {
		return 'Q';
	}
	//���û�зֳ�ʤ��
	return ' ';
}

void Game() {
	//GameΪһ����Ϸ�ĺ���
	//��������ʼ��һ�����̣�����ʹ��ħ�����֣�
	char chessBoard[MAX_ROW][MAX_COL] = { '0' };
	Init(chessBoard);
	char winner = ' ';
	while (1) {
		//1.��ӡ����(��һ��Ϊ������)
		Print(chessBoard);
		//2.��ʾ�������
		PlayerMove(chessBoard);
		//3.�����Ϸ�Ƿ����
		winner = Check(chessBoard);
		if (winner != ' ') {
			break;
		}
		//4.��������
		ComputerMove(chessBoard);
		//5.�����Ϸ�Ƿ����
		winner = Check(chessBoard);
		if (winner != ' ') {
			break;
		}//6.�ص�1����ִ��
	}
	Print(chessBoard);
	if (winner == 'X') {
		printf("������������\n");
	}
	else if (winner == 'O') {
		printf("����ˣ����Զ��򲻹�\n");
	}
	else
		printf("����ˣ��͵������忪\n");
}

int main() {
	while (1) {
		int choice = Menu();
		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			//��ʼ��Ϸ
			Game();
		}
		else {
			printf("����������������������!\n");
		}
	}
	system("pause");
	return 0;
}