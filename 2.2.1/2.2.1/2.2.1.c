#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct	Queue {
	int* pBase;
	int front;
	int rear;
}QUEUE;
 
void init(QUEUE*);
bool en_queue(QUEUE*, int);
void traverse_queue(QUEUE*);
bool full_queue(QUEUE*);
bool out_queue(QUEUE*, int*);
bool empty_queue(QUEUE* );

int main() {
	QUEUE Q;
	int val;
	init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	en_queue(&Q, 7);
	traverse_queue(&Q);
	printf("\n");
	out_queue(&Q, &val);
	traverse_queue(&Q);
	printf("\n");
	printf("%d ", val);
	return 0;
}

void init(QUEUE* pQ) {
	pQ->pBase = (int*)malloc(sizeof(int)*6);
	pQ->front = 0;
	pQ->rear = 0;
};

bool en_queue(QUEUE* pQ, int val) {
	if (full_queue(pQ)) {
		return false;
	}
	else {
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return true;
	}
}

bool full_queue(QUEUE* pQ) {
	if ((pQ->rear + 1) % 6==pQ->front) {
		return true;
	}
	else
		return false;
}

void traverse_queue(QUEUE* pQ) {
	int i = pQ->front;
	while (i != pQ->rear) {
		printf("%d ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
}

bool out_queue(QUEUE* pQ, int* val) {
	if (empty_queue(pQ)) {
		return false;
	}
	else {
		*val = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
		return true;
	}
}

bool empty_queue(QUEUE* pQ) {
	if (pQ->front == pQ->rear) {
		return true;
	}
	else
		return false;
}