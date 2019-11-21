#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 10;
	int i = 1;
	int Factorial=1;
	int tmp;
	for (; i < 11; i++) {
		tmp = Factorial;
		Factorial = i * tmp;
	}
	printf("%d\n", Factorial);
	system("pause");
	return 0;
}