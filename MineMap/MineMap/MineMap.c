#define MAX_ROW 9
#define MAX_COL	9
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void Menu() {
	printf("========================\n");
	printf("欢迎来到扫雷游戏\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("=======================\n");
	printf("请输入您的选择\n");
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
		printf("请输入想要翻开的位置\n");
		scanf("%d %d", row, col);
		if (map[*row][*col] != '*') {
			printf("该位置已经翻开了，请重输\n:");
			continue;
		}
		if (*row < 0 || *row >= MAX_ROW || *col < 0 || *col >= MAX_COL) {
			printf("您的输入有误，请重试\n");
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
		printf("踩雷！你输了\n");
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
	//1.打印两个地图并初始化    'X'表示地雷 一共有9个雷
	char showMap[MAX_ROW][MAX_COL];
	char mineMap[MAX_ROW][MAX_COL];
	Init(showMap,mineMap);
	srand((unsigned)time(0));
	int count;
	while (1) {
		//2.打印地图
		Print(showMap);
		//3.让玩家选择翻开的坐标，检查坐标是否合理
		int row = 0;
		int col = 0;
		Input(showMap,&row, &col);
		//4.判断该坐标是否有雷 如果有 游戏结束失败
		if(Check(mineMap, row, col)) {
			Print(mineMap);
			break;
		}

		//5.检查此位置是否为最后一个位置 如果是 游戏结束获胜
		if (CheckLast(&count)==71) {
			printf("恭喜你 你赢了\n");
		}
		//6.更新当前位置，把*替换为当前周围的雷数
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
			printf("再见\n");
		}
		else
			printf("您的输入有误\n");
		
	}
	system("pause");
	return 0;
}