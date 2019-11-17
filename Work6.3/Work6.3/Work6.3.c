#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
void leap(int year) {
	if ((year % 4 == 0 )& (year % 100 != 0 )|| year % 400 == 0) {
		printf("此年是闰年\n");
	}
	else {
		printf("此年不是闰年\n")
	}
}
int main() {
	int year = 0;
	printf("请输入年份\n");
	scanf("%d", &year);
	leap(year);
	system("pause");
	return 0;
}