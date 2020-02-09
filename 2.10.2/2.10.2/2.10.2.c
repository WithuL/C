#include<stdio.h>
#include<stdlib.h>
int searchInsert(int* nums, int numsSize, int target) {
	int i = 0;
	int j = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] == target) {
			return i;
		}
		else if (nums[i] < target) {
			j++;
		}
	}
	return j;
}
int main() {
	int nums[] = { 1,3,5,6 };
	int numsSize = sizeof(nums) / sizeof(int);
	int target = 5;
	printf("%d\n", searchInsert(nums, numsSize, target));
	return 0;
}