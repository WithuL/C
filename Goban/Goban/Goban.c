#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 15
#define MAX_COL 15
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//游戏介绍
//棋盘大小为15X15
//人和机器，谁的五颗棋子先连成一条线则为谁赢
//人的棋子为'X',电脑为'O' 人先下
void Menu() {
	printf("=======欢迎来到五子棋游戏！=======\n");
	printf("=======1.开始游戏================\n");
	printf("=======2.退出游戏================\n");
	printf("请输入您的选择:\n");
}

void Init(char chessboard[MAX_ROW][MAX_COL]){
	//对棋盘进行初始化
	memset(chessboard, ' ', MAX_ROW*MAX_COL);
}

//打印棋盘（第一次棋盘全为空格）
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

//玩家落子
void PlayerMove(char chessboard[MAX_ROW][MAX_COL]) {
	int row, col;
	printf("请输入落子位子\n");
	while (1) {
		scanf("%d %d", &row, &col);
		//条件判断，如果这个位置为非法位置，则重新输入
		if (row<0 || row>=MAX_ROW || col<0 || col>=MAX_COL) {
			printf("您的输入有误请重新输入\n");
			continue;
		}
		//条件判断，这个位置为' '，则可以进行落子
		if (chessboard[row][col] != ' ') {
			printf("该位置已经有棋子了哦\n");
			continue;
		}
		chessboard[row][col] = 'X';
		break;
	}
}

//电脑落子
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

//判断是否获胜
//1.每一行上有连续五颗棋子
//2.每一列上有连续五颗棋子
//3.写到这里下周要考机械制造工艺学，还没开始复习，心里慌的一批
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
			printf("你赢了 厉害\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("你真菜，连电脑都干不过\n");
			return comcut;
		}
	}
	//判断每一列上是否有赢家
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
			printf("恭喜你 你赢了\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("你真菜，连电脑都干不过\n");
			return comcut;
		}
	}
	//判断右对角斜线上有没有连续(左下部分)
	for (int i = 0; i <= MAX_ROW - 5; i++) {
		int count=0;
		int comcut=0;
		for (row = i; row < MAX_ROW; row++) {
			if (row > 0) {
				if (chessboard[row][row - i] == 'X') {//画图推出来的联系 i为查找次数
					if (chessboard[row - 1][row - i - 1] == 'X') {
						count += 1;
					}
					else {
						count = 0;
					}
				}
				if (chessboard[row][row - i] == 'O') {//画图推出来的联系 i为查找次数
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
			printf("你赢了 陕科大棋王！\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("你真菜，连电脑都干不过\n");
			return comcut;
		}
	}
	//右上部份
	for (int i = 0; i <= MAX_ROW - 5; i++) {
		int count=0;
		int comcut=0;
		for (col = i; col < MAX_ROW; col++) {
			if (col > 0) {
				if (chessboard[col - i][col] == 'X') {//画图推出来的联系 i为查找次数
					if (chessboard[col - i - 1][col - 1] == 'X') {
						count += 1;
					}
					else {
						count = 0;
					}
				}
				if (chessboard[col - i][col] == 'O') {//画图推出来的联系 i为查找次数
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
			printf("你赢了 陕科大棋王！\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("你真菜，连电脑都干不过\n");
			return comcut;
		}
	}
	//左斜线上半部分
	for (int i = MAX_ROW - 1; i >= 4; i--) {
		int count=0;
		int comcut=0;
		for (row = i; row >= 0; row--) {
			if (chessboard[row][i - row] == 'X') {//画图推出来的联系 i为查找次数
				if (chessboard[row + 1][i - row - 1] == 'X') {
					count += 1;
				}
				else {
					count = 0;
				}
			}
			if (chessboard[row][i - row] == 'O') {//画图推出来的联系 i为查找次数
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
			printf("你赢了 陕科大棋王！\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("你真菜，连电脑都干不过\n");
			return comcut;
		}
	}
	//左斜线下半部分
	for (int i = 0; i <= MAX_ROW - 5; i++) {
		int count=0;
		int comcut=0;
		for (col = i; col < MAX_ROW; col++) {
			if (chessboard[MAX_ROW - col - 2][col] == 'X') {//画图推出来的联系 i为查找次数
				if (chessboard[MAX_ROW - col - 1][col - 1] == 'X') {
					count += 1;
				}
				else {
					count = 0;
				}
			}
			if (chessboard[MAX_ROW - col - 2][col] == 'O') {//画图推出来的联系 i为查找次数
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
			printf("你赢了 陕科大棋王！\n");
			return count;
		}
		if (comcut == 4) {
			Print(chessboard);
			printf("你真菜，连电脑都干不过\n");
			return comcut;
		}
	}
	return 0;
}

void Game(char chessboard[MAX_ROW][MAX_COL]) {
	//游戏步骤；
	//1.创建两个空棋盘
	Init(chessboard);
	while (1) {
		//2.打印棋盘(首次为空棋盘)
		Print(chessboard);
		//3.玩家落子（提示玩家落子)
		PlayerMove(chessboard);
		//4.检查游戏是否结束
		if (Check(chessboard)) {
			break;
		}
		//5.电脑落子
		ComputerMove(chessboard);
		//6.检查游戏是否结束
		if (Check(chessboard)) {
			break;
		}
		//7.如果未结束返回2

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
			printf("您的输入有误，请重新输入!\n");
		}
	}
	system("pause");
	return 0;
}