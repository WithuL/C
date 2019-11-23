//游戏步骤
//1.定义一个字符型二维数组，x表示玩家棋子，o表示电脑棋子，空白' '表示这个地方未落子
//2.游戏开始，先打印一个棋盘（空白棋盘）
//3.提示玩家落子
//4.检查游戏是否结束
//5.电脑落子
//6.检查游戏是否结束
//如果未结束就返回2
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 3
#define MAX_COL 3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int Menu() {
	printf("===========================\n");
	printf("========欢迎来到三子棋=======\n");
	printf("========输入1开始游戏========\n");
	printf("========输入0退出游戏========\n");
	printf("===========================\n");
	printf("请输入您的选择\n");
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
		printf("+++++++\n");//打印分隔符
		printf("|%c|%c|%c|", chessBoard[row][0], chessBoard[row][1], chessBoard[row][2]);//打印每行元素
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
	printf("轮到玩家落子\n");
	while (1) {
		printf("请输入您要落子的坐标(行)(列)\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row<0||row>=MAX_ROW||col<0||col>=MAX_COL) {
			printf("您的输入有误，请重新输入！\n");
			continue;
		}
		if (chessBoard[row][col] != ' ') {
			printf("这个位置已经有子了\n");
			continue;
		}
		chessBoard[row][col] = 'X';
		break;
	}
}

void ComputerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("轮到电脑落子了\n");
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
	//有下面四种情况
	//1.玩家赢     返回X
	//2.电脑赢     返回O
	//3.和棋       返回Q
	//4.未分出胜负  'O'

	//检查行上有没有连续三个相同的
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '&&
			chessBoard[row][0] == chessBoard[row][1] &&
			chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	//检查列上有没有连续三个相同的
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '&&
			chessBoard[0][col] == chessBoard[1][col] &&
			chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	//检查对角线上有没有相同的
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
	//检查是否为和棋  棋盘下满，未分胜负
	if (IsFull(chessBoard)) {
		return 'Q';
	}
	//如果没有分出胜负
	return ' ';
}

void Game() {
	//Game为一局游戏的函数
	//创建并初始化一个棋盘，不能使用魔幻数字，
	char chessBoard[MAX_ROW][MAX_COL] = { '0' };
	Init(chessBoard);
	char winner = ' ';
	while (1) {
		//1.打印棋盘(第一次为空气盘)
		Print(chessBoard);
		//2.提示玩家落子
		PlayerMove(chessBoard);
		//3.检查游戏是否结束
		winner = Check(chessBoard);
		if (winner != ' ') {
			break;
		}
		//4.电脑落子
		ComputerMove(chessBoard);
		//5.检查游戏是否结束
		winner = Check(chessBoard);
		if (winner != ' ') {
			break;
		}//6.回到1继续执行
	}
	Print(chessBoard);
	if (winner == 'X') {
		printf("你是真滴厉害嗷\n");
	}
	else if (winner == 'O') {
		printf("你真菜，电脑都打不过\n");
	}
	else
		printf("你真菜，和电脑五五开\n");
}

int main() {
	while (1) {
		int choice = Menu();
		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			//开始游戏
			Game();
		}
		else {
			printf("您的输入有误，请重新输入!\n");
		}
	}
	system("pause");
	return 0;
}