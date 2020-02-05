#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct BTNode {
	int data;
	struct BTNode* pLchild;
	struct BTNode* pRchild;
};

struct BTNode* CreateBTree() {
	struct BTNode* pA = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pB = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pC = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pD = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pE = (struct BTNode*)malloc(sizeof(struct BTNode));
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = NULL;
	pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = NULL;
	pE->pRchild = NULL;
	return pA;
}

void PreTraverseBTree(struct BTNode* pT) {	//�������
	if (pT != NULL) {
		printf("%c\n", pT->data);
		if ((pT->pLchild) != NULL) {		//pLchild���Դ�������������
			PreTraverseBTree(pT->pLchild);
		}
		if ((pT->pRchild) != NULL) {		//pLchild���Դ�������������
			PreTraverseBTree(pT->pRchild);
		}
	}
}

void InTraverseBTree(struct BTNode* pT) {	//�������
	if (pT != NULL) {
		if ((pT->pLchild) != NULL) {
			InTraverseBTree(pT->pLchild);
		}
		printf("%c\n", pT->data);
		if ((pT->pRchild) != NULL) {		
			InTraverseBTree(pT->pRchild);
		}
	}
}

void PostTraverseBTree(struct BTNode* pT) {	//�������
	if (pT != NULL) {
		if ((pT->pLchild) != NULL) {
			PostTraverseBTree(pT->pLchild);
		}
		if ((pT->pRchild) != NULL) {
			PostTraverseBTree(pT->pRchild);
		}
		printf("%c\n", pT->data);
	}
}
 
int main() {
	struct BTNode* pT = CreateBTree();
	printf("���������\n");
	PreTraverseBTree(pT);
	printf("���������\n");
	InTraverseBTree(pT);
	printf("���������\n");
	PostTraverseBTree(pT);
	return 0;
}