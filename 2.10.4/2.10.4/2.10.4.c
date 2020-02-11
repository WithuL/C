#include<stdio.h>
#include<stdlib.h>
int pivotIndex(int* nums, int numsSize) {
	int i = 0;
	int j = 0;
	int leftSum = 0;
	int rightSum = 0;
	for (i = 0; i < numsSize; i++) {
		if ((i == 0) || (i == numsSize - 1)) {
			continue;
		}
		for (j = 0; j < i; j++) {
			leftSum += nums[j];
		}
		for (j = i+1; j < numsSize; j++) {
			rightSum += nums[j];
		}
		if (leftSum == rightSum) {
			return i;
		}
	}
	return -1;
}
int main() {
	int nums[] = { 1,7,3,6,5,6 };
	int i = pivotIndex(nums, 6);
	printf("%d\n", i);
	return 0;
}