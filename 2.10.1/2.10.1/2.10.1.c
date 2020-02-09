#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void Init(int* a,int* nums, int numsSize, int k) {
	int i = 0;
	int j = 0;
	for (i = 0,j=k; i < numsSize,j< numsSize; i++,j++) {
		a[j] = nums[i];
	}
	for (i = numsSize-k, j = 0; i < numsSize, j < k; i++, j++) {
		a[j] = nums[i];
	}
}
void rotate(int* nums, int numsSize, int k) {
	if (numsSize < k) {
		k = k - numsSize;
	}
	int right = numsSize - k;
	int left = k;
	int* a = (int*)malloc(sizeof(int) * numsSize);
	Init(a, nums, numsSize, k);
	int i = 0;
	for (i = 0; i < numsSize; i++) {
		nums[i] = a[i];
	}
	free(a);
}
int main() {
	int nums[] = { 1, 2 };
	int numsSize = sizeof(nums) / sizeof(int);
	int k = 3;
	for (int i = 0; i < numsSize; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	rotate(nums, numsSize, k);
	for (int i = 0; i < numsSize; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}