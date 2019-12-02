#include<stdio.h>
#include <stdlib.h>
int main(){
	int m, n, i, j;
	int t = 1;
	printf("请输入整数m n:");
	scanf("%d %d", &m, &n);
	if (m > n)
	{
		j = m;
	}
	else
	{
		j = n;
	}

	for (i = 1; i < j; i++)
	{
		if (m%i == 0 && n%i == 0)
		{
			m = m / i;
			n = n / i;
			t = t * i;
			i = 1;  
		}
	}
	printf("这两个数的最大公约数为%d,最小公倍数为%d\n", t, t*m*n);
	return 0;
}