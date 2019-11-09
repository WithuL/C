#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j;
	for (i = 100; i <= 200; i++)
	{
		for (j = 2; j <= i - 1; j++)
		{
			if (i%j == 0)
				break;
		}
		if (j == i)
			printf("%d ", i);
	}
	printf("\n");
	system("pause");
	return 0;
}