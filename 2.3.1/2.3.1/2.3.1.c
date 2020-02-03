#include<stdio.h>
#include<stdlib.h>

int  sum(int a) {
	if (a == 1) {
		return 1;
	}
	return a + sum(a - 1);
}

int jc(b) {
	if (b == 1) {
		return 1;
	}
	return b * jc(b - 1);
}
int main() {
	int a = 100;
	int b = 5;
	printf("%d\n", sum(a));
	printf("%d\n", jc(b));
	return 0;
