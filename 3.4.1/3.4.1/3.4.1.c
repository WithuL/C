#include<stdio.h>
int* exchange(int* nums, int numsSize, int* returnSize) {
	int* fast = &nums[numsSize-1];
	int* low = nums;
	int tmp = 0;
	while (low < fast) {
		if ((*low & 1)!= 0) low++;
		if ((*fast & 1)== 0) fast--;
		if ((*low & 1) == 0 && (*fast & 1) != 0&&low<fast) {
			tmp = *low;
			*low = *fast;
			*fast = tmp;
		}
	}
	*returnSize = numsSize;
	for (int i = 0; i < numsSize;i++){
		printf("%d ", nums[i]);
	}
	return nums;
}
int main() {
	int nums[] = { 1,2,3,4};
	int numsSize = 4;
	int returnSize = 0;
	exchange(nums, numsSize, &returnSize);
	return 0;
}