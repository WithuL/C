#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void printff(int* A, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int i;
	for (i = digitsSize  -1; i >= 0; i--) {
		digits[i] = (digits[i] + 1) % 10;
		if (digits[i] != 0) {
			break;
		}
	}
	*returnSize = digitsSize;
	if (digits[0] == 0) {
		int* A = (int*)malloc(sizeof(int) * (digitsSize + 1));
		A[0] = 1;
		for (i = 1; i < digitsSize + 1; i++) {
			A[i] = 0;
		}
		*returnSize = digitsSize + 1;
		printff(A, digitsSize + 1);
		return A;
	}
	else {
		printff(digits, digitsSize);
		return digits;
	}
}
int main() {
	int digits[] = { 9};
	int digitsSize =sizeof(digits)/sizeof(int) ;
	int returnSize = 0;
	plusOne(digits, digitsSize, &returnSize);
	return 0;
}