#define MAX_ROW 9
#define MAX_COL	9
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void Menu() {
	printf("========================\n");
	printf("��ӭ����ɨ����Ϸ\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("=======================\n");
	printf("����������ѡ��\n");
}
void Init(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL]) {
	memset(showMap, '*', MAX_ROW*MAX_COL);
	memset(mineMap, ' ', MAX_ROW*MAX_COL);
	int row;
	int col;
	int i=0 ;
	while(i<8) {
		row = rand() % 10;
		col = rand() % 10;
		if (mineMap[row][col] != 'X') {
			mineMap[row][col] = 'X';
			i = i + 1;
		}
	}
}
void Print(char map[MAX_ROW][MAX_COL]) {
	int row;
	int col;
	for (row = 0; row < MAX_ROW; row++) {
		for (col = 0; col < MAX_COL; col++) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
void Input(char map[MAX_ROW][MAX_COL],int* row, int* col) {
	while (1) {
		printf("��������Ҫ������λ��\n");
		scanf("%d %d", row, col);
		if (map[*row][*col] != '*') {
			printf("��λ���Ѿ������ˣ�������\n:");
			continue;
		}
		if (*row < 0 || *row >= MAX_ROW || *col < 0 || *col >= MAX_COL) {
			printf("������������������\n");
			continue;
		}
		break;
	}
}
int Check(char mineMap[MAX_ROW][MAX_COL], int row, int col) {
	if (mineMap[row][col] != 'X') {
		return 0;
	}
	else {
		printf("���ף�������\n");
		return 1;
	}
}
int CheckLast(int* count) {
	*count += 1;
	return *count;
}
void Up(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL], int  row, int  col) {
	int count = 0;
	int r, c;
	for (r = row - 1; r <= row + 1; r++) {
		for (c = col - 1; c <= col + 1; c++) {
			if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
				continue;
			}
			if (mineMap[r][c] == 'X') {
				count += 1;
			}
		}
	}
	showMap[row][col] = count + '0';
}
void Game() {
	//1.��ӡ������ͼ����ʼ��    'X'��ʾ���� һ����9����
	char showMap[MAX_ROW][MAX_COL];
	char mineMap[MAX_ROW][MAX_COL];
	Init(showMap,mineMap);
	srand((unsigned)time(0));
	int count;
	while (1) {
		//2.��ӡ��ͼ
		Print(showMap);
		//3.�����ѡ�񷭿������꣬��������Ƿ����
		int row = 0;
		int col = 0;
		Input(showMap,&row, &col);
		//4.�жϸ������Ƿ����� ����� ��Ϸ����ʧ��
		if(Check(mineMap, row, col)) {
			Print(mineMap);
			break;
		}

		//5.����λ���Ƿ�Ϊ���һ��λ�� ����� ��Ϸ������ʤ
		if (CheckLast(&count)==71) {
			printf("��ϲ�� ��Ӯ��\n");
		}
		//6.���µ�ǰλ�ã���*�滻Ϊ��ǰ��Χ������
		Up(showMap, mineMap, row, col);
	}
	
}
int main() {
	while (1) {
		Menu();
		int choice = 0;
		scanf("%d", &choice);
		if (choice == 1)
			Game();
		else if (choice == 0) {
			printf("�ټ�\n");
		}
		else
			printf("������������\n");
		
	}
	system("pause");
	return 0;
}