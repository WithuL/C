#include<stdio.h>
#include<stdlib.h>
typedef struct student {
	long long sid;
	char name[200];
	char sex[20];
}* PSTU,STU;  //����������struct student* �ı���ΪPSTU,����struct student �ı���ΪSTU.
int main() {
	STU st = { 00000,"��ĳ","��" };
	PSTU pst = &st;
	pst->sid = 201705020218;
	printf("%d\n", pst->sid);
	system("pause");
	return 0;
}