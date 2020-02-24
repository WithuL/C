#include<Stdio.h>
int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0) {
		return 0;
	}
	int p = 0;
	int q= p;
	for (p=0; p < numsSize; p++) {
		if (nums[p] != nums[q]) {
			nums[q++] = nums[p];
		}
	}
	return q;
}
int main() {
	int returnSize = 0;
	int nums[] = { 1,1,2 };
	int numsSize = 3;
	returnSize = removeDuplicates(nums, numsSize);
	return 0;
}