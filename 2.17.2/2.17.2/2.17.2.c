#include<stdio.h>
int findRepeatNumber(int* nums, int numsSize) {
	int i;
	for (i = 0; i < numsSize;) {
		if (nums[i] != i) {
			if (nums[i] != nums[nums[i]]){
				int tmp = nums[nums[i]];
				nums[nums[i]] = nums[i];
				nums[i] = tmp;
			}
			else {
				return nums[i];
			}
		}
		else {
			i++;
		}
	}
	return -1;
}
int main() {
	int nums[] = {2, 3, 1, 0, 2, 5, 3};
	int numsSize = sizeof(nums) /sizeof(int);
	return findRepeatNumber(nums, numsSize);
}