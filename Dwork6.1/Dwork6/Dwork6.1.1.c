#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 1;
	int b = 1;
	int tmp;
	int i;
	for (i = 3; i <= 6; i++) {
		tmp = a + b;
		a = b;
		b = tmp;
	}
	printf("%d\n",tmp);
	system("pause");
}