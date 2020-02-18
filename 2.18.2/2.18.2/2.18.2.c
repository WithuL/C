//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//typedef struct ListNode {
//	int val;
//	struct ListNode* next;
//}Node,*PNode;
//PNode Creat_Lits(PNode head) {
//	head = (PNode)malloc(sizeof(Node));
//	PNode pHead = head;
//	if (pHead == NULL) {
//		printf("内存分配失败\n");
//		exit (-1);
//	}
//	printf("请输入链表节点个数:\n");
//	int len = 0;
//	scanf("%d", &len);
//	printf("请输入节点数据:\n");
//	for (int i = 0; i < len; i++) {
//		PNode pNew = (PNode)malloc(sizeof(Node));
//		scanf("%d", &pNew->val);
//		pHead->next = pNew;
//		pNew->next = NULL;
//		pHead = pNew;
//	}
//	return head;
//}
//int IsEmpty(PNode head) {
//	PNode pHead = head;
//	int i = 0;
//	while (pHead->next == NULL) {
//		return 1;
//	}
//	return 0;
//}
//void Traverse(PNode head) {
//	PNode pHead = head;
//	if(pHead->next != NULL) {
//		Traverse(pHead->next);
//		printf("%d\n", pHead->val);
//	}
//}
//
//int main() {
//	PNode head=NULL;
//	head=Creat_Lits(head);
//	if (IsEmpty(head))
//		return 0;
//	Traverse(head);
//	return 0;
//}
