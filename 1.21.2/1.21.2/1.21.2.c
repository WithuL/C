#define _CRT_SECURE_NO_WARNINGS
#include<Stdlib.h>
#include<Stdio.h>
#include<malloc.h>
typedef struct Noed {
	int date;//数据域
	struct Node* pNext;//指针域
}*PNODE, NODE;	//PONDE等价于stuct Node*，NODE等价于stuct Node
PNODE create_list(){
	int len;//用来存放有效结点的个数
	int i;
	int val;//用来临时存放用户输入的节点的值
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	if (pHead == NULL) {
		printf("内存分配失败!\n");
		exit(-1);
	}

	printf("请输入您需要生成链表节点的个数: \n");
	scanf("%d", &len);
	for (i = 0; i < len; i++) {
		printf("请输入第%d个节点的值", i + 1);
		scanf("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew) {
			printf("内存分配失败！\n");
			exit(-1);
		}
		pNew->date = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
void  traverse_list(PNODE pHead) {
	PNODE p = pHead->pNext;
	while (p!= NULL) {
		printf("%d ", p->date);
		p = p->pNext;
	}
	printf("\n");
}
int main() {
	PNODE pHead = NULL;
	pHead = create_list();//创建一个非循环单链表
	traverse_list(pHead);
	return 0;
}
