#include <stdio.h>

void print_excel();		//声明九九乘法表打印函数
void print_chess();		//声明国际象棋棋盘打印函数

int main(void)
{
	print_excel();
	print_chess();
	system("pause");
	return 0;
}

void print_excel()
{
	int i, j;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < i + 1; j++)
		{
			printf(" %d*%d=%2d ", i, j, i*j);
		}
		printf("\n");
	}
	printf("\n");
}

void print_chess()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				printf("%c%c", 168, 128);
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}