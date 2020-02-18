#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* Creat_Lits(struct ListNode* head) {
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* pHead = head;
	if (pHead == NULL) {
		printf("内存分配失败\n");
		exit(-1);
	}
	printf("请输入链表节点个数:\n");
	int len = 0;
	scanf("%d", &len);
	printf("请输入节点数据:\n");
	for (int i = 0; i < len; i++) {
		struct ListNode* pNew = (struct ListNode*)malloc(sizeof(struct ListNode));
		scanf("%d", &pNew->val);
		pHead->next = pNew;
		pNew->next = NULL;
		pHead = pNew;
	}
	return head;
}
int Count(struct ListNode* head){
	int i = 0;
	struct ListNode* pHead = head->next;
	while (pHead != NULL) {
		i++;
		pHead = pHead->next;
	}
	return i;
}
void Traverse(struct ListNode* head, int* ret, int i) {
	struct ListNode* pHead = head;
	if (pHead->next != NULL) {
		Traverse(pHead->next,ret,i+1);
		printf("%d ", pHead->next->val);
	}
}
int* reversePrint(struct ListNode* head, int* returnSize) {
	if (returnSize == 0) {
		return 0;
	}
	int* ret = (int*)malloc(sizeof(int)*(*returnSize));
	int i = 0;
	Traverse(head,ret, i);
	return ret;
}
int main() {
	struct ListNode* head = NULL;
	head=Creat_Lits(head);
	int returnSize = Count(head);
	reversePrint(head,&returnSize);
	return 0;
}
