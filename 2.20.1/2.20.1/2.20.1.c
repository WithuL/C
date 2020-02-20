#include<stdio.h>
#include<malloc.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int left = 0;
	int right = numsSize - 1;
	int* ret = (int*)malloc(sizeof(int) * 2);
	while (nums[left] + nums[right] != target) {
		if (nums[left] + nums[right] > target)
			right--;
		else
			left++;
	}
	*returnSize = 2;
	ret[0] = nums[left];
	ret[1] = nums[right];
	printf("%d %d", ret[0], ret[1]);
	return ret;
}
int main() {
	int nums[] = { 2,7,11,15 };
	int numsSize = 4;
	int target = 9;
	int returnSize = 0;
	twoSum(nums, numsSize, target, &returnSize);
	return 0;
}