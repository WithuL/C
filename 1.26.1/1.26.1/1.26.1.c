#include<Stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool containsDuplicate(int* nums, int numsSize) {
	int i, j;
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] == nums[j]) {
				return 0;
			}
		}
	}
	return 1;
}
int main() {
	int nums[5] = { 1,2,3,4,5 };
	int numsSize = 5;
	return containsDuplicate(nums, numsSize);
}
