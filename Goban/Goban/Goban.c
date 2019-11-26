#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 15
#define MAX_COL 15
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//��Ϸ����
//���̴�СΪ15X15
//�˺ͻ�����˭���������������һ������Ϊ˭Ӯ
//�˵�����Ϊ'X',����Ϊ'O' ������
void Menu() {
	printf("=======��ӭ������������Ϸ��=======\n");
	printf("=======1.��ʼ��Ϸ================\n");
	printf("=======2.�˳���Ϸ================\n");
	printf("����������ѡ��:\n");
}

void Init(char chessboard[MAX_ROW][MAX_COL]){
	//�����̽��г�ʼ��
	memset(chessboard, ' ', MAX_ROW*MAX_COL);
}

//��ӡ���̣���һ������ȫΪ�ո�
void Print(char chessboard[MAX_ROW][MAX_COL]) {
	printf("\n");
	int row,col;
	printf("  |0 1 2 3 4 5 6 7 8 9 A B C D E\n");
	printf("  ------------------------------\n");
	for (row = 0; row < MAX_ROW; row++) {
		if (row <= 9) {
			printf(" %d|", row);
		}
		else {
			printf("%d|", row);
		}
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
	while (1) {
		scanf("%d %d", &row, &col);
		//�����жϣ�������λ��Ϊ�Ƿ�λ�ã�����������
		if (row<0 || row>=MAX_ROW || col<0 || col>=MAX_COL) {
			printf("����������������������\n");
			continue;
		}
		//�����жϣ����λ��Ϊ' '������Խ�������
		if (chessboard[row][col] != ' ') {
			printf("��λ���Ѿ���������Ŷ\n");
			continue;
		}
		chessboard[row][col] = 'X';
		break;
	}
}

//��������
void ComputerMove(char chessboard[MAX_ROW][MAX_COL]) {
	int row;
	int col;
	while (1) {
		row = rand() % MAX_ROW;
		col = rand() % MAX_COL;
		if (chessboard[row][col] != ' ') {
			continue;
		}
		chessboard[row][col] = 'O';
		break;
	}
}

//�ж��Ƿ��ʤ
//1.ÿһ�����������������
//2.ÿһ�����������������
//3.д����������Ҫ����е���칤��ѧ����û��ʼ��ϰ������ŵ�һ��
int Check(char chessboard[MAX_ROW][MAX_COL]) {
	int row;
	int col;
	for (row = 0; row < MAX_ROW; row++) {
		int count = 0;
		int comcut = 0;
		for (col = 0; col < MAX_COL; col++)
			if (row > 0) {
				if (chessboard[row][col] == 'X') {
					if (chessboard[row][col - 1] == 'X') {
						count += 1;
					}
					else {
						count = 0;
					}
				}
				if (chessboard[row][col] == 'O') {
					if (chessboard[row][col - 1] == 'O') {
						comcut+=1;
					}
					else {
						comcut = 0;
					}
				}
			}
		if (count == 4) {
			Print(chessboard);
			printf("��Ӯ�� ����\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("����ˣ������Զ��ɲ���\n");
			return comcut;
		}
	}
	//�ж�ÿһ�����Ƿ���Ӯ��
	for (col = 0; col < MAX_COL; col++) {
		int count = 0;
		int comcut = 0;
		for (row = 0; row < MAX_ROW; row++)
			if (col > 0) {
				if (chessboard[row][col] == 'X') {
					if (chessboard[row - 1][col] == 'X') {
						count += 1;
					}
					else {
						count = 0;
					}
				}
				if (chessboard[row][col] == 'O') {
					if (chessboard[row - 1][col] == 'O') {
						comcut += 1;
					}
					else {
						comcut= 0;
					}
				}
			}
		if (count == 4) {
			Print(chessboard);
			printf("��ϲ�� ��Ӯ��\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("����ˣ������Զ��ɲ���\n");
			return comcut;
		}
	}
	//�ж��ҶԽ�б������û������(���²���)
	for (int i = 0; i <= MAX_ROW - 5; i++) {
		int count=0;
		int comcut=0;
		for (row = i; row < MAX_ROW; row++) {
			if (row > 0) {
				if (chessboard[row][row - i] == 'X') {//��ͼ�Ƴ�������ϵ iΪ���Ҵ���
					if (chessboard[row - 1][row - i - 1] == 'X') {
						count += 1;
					}
					else {
						count = 0;
					}
				}
				if (chessboard[row][row - i] == 'O') {//��ͼ�Ƴ�������ϵ iΪ���Ҵ���
					if (chessboard[row - 1][row - i - 1] == 'O') {
						comcut += 1;
					}
					else {
						comcut= 0;
					}
				}
			}
		}
		if (count == 4) {
			Print(chessboard);
			printf("��Ӯ�� �¿ƴ�������\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("����ˣ������Զ��ɲ���\n");
			return comcut;
		}
	}
	//���ϲ���
	for (int i = 0; i <= MAX_ROW - 5; i++) {
		int count=0;
		int comcut=0;
		for (col = i; col < MAX_ROW; col++) {
			if (col > 0) {
				if (chessboard[col - i][col] == 'X') {//��ͼ�Ƴ�������ϵ iΪ���Ҵ���
					if (chessboard[col - i - 1][col - 1] == 'X') {
						count += 1;
					}
					else {
						count = 0;
					}
				}
				if (chessboard[col - i][col] == 'O') {//��ͼ�Ƴ�������ϵ iΪ���Ҵ���
					if (chessboard[col - i - 1][col - 1] == 'O') {
						comcut += 1;
					}
					else {
						comcut= 0;
					}
				}
			}
		}
		if (count == 4) {
			Print(chessboard);
			printf("��Ӯ�� �¿ƴ�������\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("����ˣ������Զ��ɲ���\n");
			return comcut;
		}
	}
	//��б���ϰ벿��
	for (int i = MAX_ROW - 1; i >= 4; i--) {
		int count=0;
		int comcut=0;
		for (row = i; row >= 0; row--) {
			if (chessboard[row][i - row] == 'X') {//��ͼ�Ƴ�������ϵ iΪ���Ҵ���
				if (chessboard[row + 1][i - row - 1] == 'X') {
					count += 1;
				}
				else {
					count = 0;
				}
			}
			if (chessboard[row][i - row] == 'O') {//��ͼ�Ƴ�������ϵ iΪ���Ҵ���
				if (chessboard[row + 1][i - row - 1] == 'O') {
					comcut += 1;
				}
				else {
					comcut= 0;
				}
			}
		}
		if (count == 4) {
			Print(chessboard);
			printf("��Ӯ�� �¿ƴ�������\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("����ˣ������Զ��ɲ���\n");
			return comcut;
		}
	}
	//��б���°벿��
	for (int i = 0; i <= MAX_ROW - 5; i++) {
		int count=0;
		int comcut=0;
		for (col = i; col < MAX_ROW; col++) {
			if (chessboard[MAX_ROW - col - 2][col] == 'X') {//��ͼ�Ƴ�������ϵ iΪ���Ҵ���
				if (chessboard[MAX_ROW - col - 1][col - 1] == 'X') {
					count += 1;
				}
				else {
					count = 0;
				}
			}
			if (chessboard[MAX_ROW - col - 2][col] == 'O') {//��ͼ�Ƴ�������ϵ iΪ���Ҵ���
				if (chessboard[MAX_ROW - col - 1][col - 1] == 'O') {
					comcut += 1;
				}
				else {
					comcut = 0;
				}
			}
		}
		if (count == 4) {
			Print(chessboard);
			printf("��Ӯ�� �¿ƴ�������\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("����ˣ������Զ��ɲ���\n");
			return comcut;
		}
	}
	return 0;
}

void Game(char chessboard[MAX_ROW][MAX_COL]) {
	//��Ϸ���裻
	//1.��������������
	Init(chessboard);
	while (1) {
		//2.��ӡ����(�״�Ϊ������)
		Print(chessboard);
		//3.������ӣ���ʾ�������)
		PlayerMove(chessboard);
		//4.�����Ϸ�Ƿ����
		if (Check(chessboard)) {
			break;
		}
		//5.��������
		ComputerMove(chessboard);
		//6.�����Ϸ�Ƿ����
		if (Check(chessboard)) {
			break;
		}
		//7.���δ��������2

	}
}

int main() {
	while (1) {
		Menu();
		srand((unsigned)time(NULL));
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