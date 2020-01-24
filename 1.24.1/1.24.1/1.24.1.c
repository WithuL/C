#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct Node {
	int date;
	struct Node* pNext;
}NODE,*PNODE;

typedef struct Stack {
	PNODE pTop;
	PNODE pBottom;
}STACK,* PSTACK;

void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK, int*);
void clear(PSTACK);
int main() {
	STACK s;
	int val=0;
	init(&s);
	push(&s,1);
	push(&s,2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	push(&s, 6);
	traverse(&s);
	if (pop(&s, &val)) {
		printf("出栈成功！出栈的元素是：%d\n", val);
	}
	traverse(&s);
	printf("清空元素\n");
	clear(&s);
	traverse(&s);
	return 0;
}

void init(PSTACK pS) {
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop) {
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	pS->pBottom = pS->pTop;
	pS->pTop->pNext = NULL;		//pS->pTop->pNext=NULL
} 

void push(PSTACK pS, int val) {
	PNODE p = (PNODE)malloc(sizeof(NODE));
	p->date = val;
	p->pNext = pS->pTop;
	pS->pTop = p;
}

void traverse(PSTACK pS) {
	PNODE p = pS->pTop;
	while (p != pS->pBottom) {
		printf("%d ", p->date);
		p = p->pNext;   
	}
	printf("\n");
}

bool empty(PSTACK pS) {
	if (pS->pTop == pS->pBottom) {
		return true;
	}
	return false;
}
bool pop(PSTACK pS, int* pVal) {   
	/*把pS所指向的栈出栈一次，并把出栈的元素保存
	pVal形参所指向的变量中，如果失败则返回false，若成功返回true；*/			
	if (empty(pS)) {
		printf("出栈失败！\n");
		return false;
	}
	else {
		PNODE r = pS->pTop;
		*pVal = r->date;
		pS->pTop = pS->pTop->pNext;
		free(r);
		r = NULL;
		return true;	
	}	
}

void clear(PSTACK pS) {
	if (empty(pS)) {
		return ;
	}
	else {
		PNODE p = pS->pTop;
		PNODE q = pS->pTop->pNext;
		while (p!=pS->pBottom) {
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
}