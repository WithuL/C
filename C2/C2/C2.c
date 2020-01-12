#include<stdio.h>
#include<stdlib.h>
int main() {
	int sum = 20;
	int temp = 0;
	int ret = 20;
	while (ret / 2 != 0)
	{
		temp = ret;
		ret = ret / 2;
		sum += ret;
		ret = temp % 2 + ret;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}