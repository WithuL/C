#include <stdio.h>
#include<stdlib.h>
int main(void)
{
	int i;
	int x = 1;
	for (i = 9; i > 0; i--)
	{
		x = (x + 1) * 2;
	}
	printf("��һ��ժ��%d������\n", x);
	system("pause");
	return 0;

}