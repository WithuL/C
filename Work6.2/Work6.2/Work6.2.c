#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b) {
	int tmp;
	tmp =*a;
	*a = *b;
	*b = tmp;
	}
int main() {
	int x = 10, y = 20;
	printf("%d   %d\n", x, y);
	swap(&x, &y);
	printf("%d   %d\n", x, y);
	system("pause");
	return 0;
}