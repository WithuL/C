#define _CRT_SECURE_NO_WARNINGS
#include<Stdlib.h>
#include<Stdio.h>
#include<malloc.h>
typedef struct Noed {
	int date;//������
	struct Node* pNext;//ָ����
}*PNODE, NODE;	//PONDE�ȼ���stuct Node*��NODE�ȼ���stuct Node
PNODE create_list(){
	int len;//���������Ч���ĸ���
	int i;
	int val;//������ʱ����û�����Ľڵ��ֵ
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	if (pHead == NULL) {
		printf("�ڴ����ʧ��!\n");
		exit(-1);
	}

	printf("����������Ҫ��������ڵ�ĸ���: \n");
	scanf("%d", &len);
	for (i = 0; i < len; i++) {
		printf("�������%d���ڵ��ֵ", i + 1);
		scanf("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew) {
			printf("�ڴ����ʧ�ܣ�\n");
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
	pHead = create_list();//����һ����ѭ��������
	traverse_list(pHead);
	return 0;
}
