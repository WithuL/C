#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int rabbit(int x);
int main(void)
{
	int n, add = 0;
	printf("请输入最终月份:");
	scanf("%d", &n);
	add = add + rabbit(n);
	printf("%d个月后兔子的总数为%d\n", n, add);
	system("pause");
	return 0;
}

int rabbit(int x)
{
	int y;
	if (x < 3)  //
	{
		y = 2;
	}
	else
	{
		y = rabbit(x - 1) + rabbit(x - 2);
		/*递归函数，第x个月兔子数量等于第x-1月与第x-2月数量之和*/
	}
	return y;
}