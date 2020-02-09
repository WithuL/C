#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void max_heap(int* returnSize, int start, int end) {
	int dad = start;
	int son = 2 * dad + 1;
	while (son <= end) {
		if (returnSize[son] < returnSize[son + 1] && (son + 1) <= end) {
			son++;
		}
		if (returnSize[dad] < returnSize[son]) {
			swap(&returnSize[dad], &returnSize[son]);
			dad = son;
			son = dad * 2 + 1;
		}
		else {
			return;
		}
	}
}
void square_arr(int* A, int ASize, int* returnSize) {
	int i = 0;
	for (i = 0; i < ASize; i++) {
		returnSize[i] = (A[i] * A[i]);
	}

}
void heap_sort(int* returnSize, int ASize) {
	int i;
	for (i = ASize / 2 - 1; i >= 0; i--) {
		max_heap(returnSize, i, ASize - 1);
	}
	for (i = ASize - 1; i > 0; i--) {
		swap(&returnSize[0], &returnSize[i]);
		max_heap(returnSize, 0, i - 1);
	}
}
int* sortedSquares(int* A, int ASize, int* returnSize) {
	returnSize = (int*)malloc(sizeof(int) * ASize);
	square_arr(A, ASize, returnSize);
	heap_sort(returnSize, ASize);
	return returnSize;
}
int main() {
	int ASize = 5;
	int* A = (int*)malloc(sizeof(int) * ASize);
	A[0] = -4;
	A[1] = -1;
	A[2] = 0;
	A[3] = 3;
	A[4] = 10;
	int* returnSize = NULL;
	returnSize = sortedSquares(A, ASize, returnSize);
	for (int i = 0; i < ASize; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	for (int i = 0; i < ASize; i++) {
		printf("%d ", returnSize[i]);
	}
	free(A);
	free(returnSize);
	return 0;
}