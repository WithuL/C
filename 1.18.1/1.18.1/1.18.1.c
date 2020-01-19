#include<stdlib.h>
#include<stdio.h>
int  containsDuplicate(int* nums, int numsSize) {
	int i, j;
	for (i = 0; i < numsSize; i++) {
		for (j = 0; j < numsSize; j++) {
			if (i != j) {
				if (nums[i] == nums[j]) {
					return 0;
				}
			}
		}
	}
	return 1;
}
int main() {
	int nums[4]= { 1,2,3,4 };
	int numsSize=4;
	system("pause");
	return containsDuplicate(nums,numsSize);
}