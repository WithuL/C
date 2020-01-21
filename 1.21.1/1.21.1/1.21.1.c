#include<stdio.h>
#include<stdlib.h>
typedef struct student {
	long long sid;
	char name[200];
	char sex[20];
}* PSTU,STU;  //代表了类型struct student* 的别名为PSTU,类型struct student 的别名为STU.
int main() {
	STU st = { 00000,"刘某","男" };
	PSTU pst = &st;
	pst->sid = 201705020218;
	printf("%d\n", pst->sid);
	system("pause");
	return 0;
}