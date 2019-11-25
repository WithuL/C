#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 15
#define MAX_COL 15
#include<stdio.h>
#include<stdlib.h>
//游戏介绍
//棋盘大小为15X15
//人和机器，谁的五颗棋子先连成一条线则为谁赢
//人的棋子为'X',电脑为'O' 人先下
void Menu() {
	printf("欢迎来到五子棋游戏！\n");
	printf("1.开始游戏\n");
	printf("2.退出游戏\n");
	printf("请输入您的选择:\n");
}

char Init(char chessboard[MAX_ROW][MAX_COL]){
	//对棋盘进行初始化
	memset(chessboard, ' ', MAX_ROW*MAX_COL);
}

//打印棋盘（第一次棋盘全为空格）
void Print(char chessboard[MAX_ROW][MAX_COL]) {
	int row,col;
	for (row = 0; row < MAX_ROW; row++) {
		for (col = 0; col < MAX_COL; col++) {
			printf("%c ", chessboard[row][col]);
		}
		printf("\n");
	}
}

//玩家落子
void PlayerMove(char chessboard[MAX_ROW][MAX_COL]) {
	int row, col;
	printf("请输入落子位子\n");
	scanf("%d %d", &row, &col);
	//条件判断，这个位置为' '，则可以进行落子
	if (chessboard[MAX_ROW][MAX_COL] == ' ') {
		chessboard[row][col] = 'X';
	}
}
void Game(char chessboard[MAX_ROW][MAX_COL]) {
	//游戏步骤；
	//1.创建两个空棋盘
	Init(chessboard[MAX_ROW][MAX_COL]);
	while (1) {
		//2.打印棋盘(首次为空棋盘)
		Print(chessboard[MAX_ROW][MAX_COL]);
		//3.玩家落子（提示玩家落子)
		PlayerMove(chessboard[MAX_ROW][MAX_COL]);
		//4.检查游戏是否结束
		Check(chessboard[MAX_ROW][MAX_COL]);
		//5.电脑落子
		ComputerMove(chessboard[MAX_ROW][MAX_COL]);
		//6.检查游戏是否结束
		Check(chessboard[MAX_ROW][MAX_COL]);
		//7.如果未结束返回2

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
			printf("您的输入有误，请重新输入!\n");
		}
	}
	system("pause");
	return 0;
}