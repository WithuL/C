#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct Node {
	int date;
	struct Node* pNext;
}NODE,* PNODE;
PNODE create_list(PNODE pHead) {
	pHead = (PNODE)malloc(sizeof(NODE));
	PNODE pTait = pHead;
	pTait->pNext = NULL;
	if (pHead == NULL) {
		printf("节点分配失败\n");
		exit(-1);
	}
	int i, len;
	printf("请输入节点个数:");
	scanf("%d", &len);
	for (i = 0; i < len; i++) {
		int val = 0;
		printf("请输入第%d个节点的数值:",i+1);
		scanf("%d", &val);
		PNODE New = (PNODE)malloc(sizeof(NODE));
		pTait->pNext = New;
		New->date = val;
		New->pNext = NULL;
		pTait = New;
	}
	return pHead;
}

bool is_empty(PNODE pHead) {
	if (pHead->pNext == NULL) {
		printf("链表为空\n");
		return false;
	}
	return true;
}

int length_list(PNODE pHead) {
	PNODE p = pHead->pNext;
	int count = 0;
	while (p != NULL) {
		count++;
		p = p->pNext;
	}
	return count;
}

bool insert_list(PNODE pHead, int pos, int val) {
	int i = 0;
	PNODE p = pHead;
	while (p!= NULL&&i<pos-1) {
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 && p == NULL) {
		printf("动态内存分配失败!\n");
		exit(-1);
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL) {
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	pNew->date = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	printf("在第%d个节点处插入%d\n", pos, val);
	return true;
}

bool delete_list(PNODE pHead, int pos, int* val) {
	int i = 0;
	PNODE p = pHead;
	while (p->pNext!= NULL && i < pos - 1) {
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 && p->pNext == NULL) {
		return false;
	}
	PNODE q = p->pNext;
	*val = q->date;
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	printf("您删除的元素为:%d\n", *val);
	return true;
}

void sort_list(PNODE pHead) {
	int i, j, tmp;
	int len = length_list(pHead);
	PNODE p,q;
	for (i = 0,p = pHead->pNext; i<len-1; i++,p = p->pNext) {
		for (j = i+1, q = p->pNext; j<len; j++,q = q->pNext) {
			if (p->date > q->date) {
				tmp = p->date;
				p->date = q->date;
				q->date = tmp;
			}
		}
	}
}
void traverse_list(PNODE pHead) {
	PNODE pTait=pHead->pNext;
	while (pTait != NULL) {
		printf("%d ", pTait->date);
		pTait = pTait->pNext;
	}
	printf("\n");
}
int main(){
	int val=616;
	PNODE pHead=NULL;
	pHead = create_list(pHead);
	traverse_list(pHead);
	is_empty(pHead);
	int len = length_list(pHead);
	printf("链表的长度为%d\n", len);
	sort_list(pHead);
	traverse_list(pHead);
	insert_list(pHead, 4, val);
	traverse_list(pHead);
	delete_list(pHead, 4, &val);
	traverse_list(pHead);
	system("pause");
	return 0;
}