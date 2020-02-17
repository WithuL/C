#include<Stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i, j;
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				returnSize[0] = i;
				returnSize[1] = j;
			}
		}
	}
	return returnSize;
}
int main() {
	int nums[] = { 2, 7, 11, 15 };
	int numsSize = sizeof(nums) / sizeof(int);
	int target = 9;
	int returnSize[2] = {0};
	twoSum(nums, numsSize, target, returnSize);
	printf("%d %d", returnSize[0], returnSize[1]);
	return 0;
}