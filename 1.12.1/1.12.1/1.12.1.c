#include<stdlib.h>
#include<stdio.h>
int removeElement(int* nums, int numsSize, int val) {
	int i = 0;
	int count = 0;
	for (int j = 0; j < numsSize; j++) {
		for (i = 0; i < numsSize-1; i++) {
			int tmp = 0;
			if (nums[i] == val) {
				tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;
			}
		}
	}
	for (i=0; i < numsSize; i++) {
		if (nums[i] == val) {
			count++;
		}
	}
	for (i = 0; i < numsSize; i++) {
		printf("%d", nums[i]);
	}
	printf("\n");
	return numsSize-count;
}
int main() {
	int nums[8] = { 0, 1, 2, 2, 3, 0, 4, 2 };
	int numsSize = 8;
	int val = 2;
	removeElement(nums,numsSize,val);
	printf("%d", removeElement(nums, numsSize, val));
	system("pause");
	return 0;
}