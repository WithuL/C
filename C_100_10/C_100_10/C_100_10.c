#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int rabbit(int x);
int main(void)
{
	int n, add = 0;
	printf("�����������·�:");
	scanf("%d", &n);
	add = add + rabbit(n);
	printf("%d���º����ӵ�����Ϊ%d\n", n, add);
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
		/*�ݹ麯������x���������������ڵ�x-1�����x-2������֮��*/
	}
	return y;
}