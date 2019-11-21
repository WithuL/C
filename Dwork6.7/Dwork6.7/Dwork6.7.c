#include<stdio.h>
#include<stdlib.h>
int prt(int a){
	if (a != 0) {
		int b = prt(a / 10);
		printf("%d  ", a % 10);
	}
	return 0;
}
int main() {
	int a = 1024;
	prt(a);
	system("pause");
	return 0;
}