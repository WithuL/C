#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool containsDuplicate(int* nums, int numsSize) {
	int i;
	for (i = 1; i < numsSize; i++) {
		if (nums[i - 1] == nums[i]) {
			return true;
		}
	}
	return false;
}

void sort(int* nums, int numsSize) {
	int i, j,tmp;
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize;j++) {
			if (nums[i] > nums[j]) {
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
	}
}

int main() {
	int nums[4] = { 1,2,3,1 };
	int numsSize = 4;
	sort(&nums[0], numsSize);
	containsDuplicate(&nums[0], numsSize);
	return 0;
}