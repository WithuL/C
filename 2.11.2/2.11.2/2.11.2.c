#include<stdio.h>
#include<stdlib.h>

int thirdMax(int* nums, int numsSize) {
	int i = 0;
	long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
	for ( i = 0; i < numsSize; i++) {
		if (nums[i] > first)
			first = nums[i];
	}
	for ( i = 0; i < numsSize; i++) {
		if (nums[i] > second&&nums[i]!=first)
			second = nums[i];
	}
	for ( i = 0; i < numsSize; i++) {
		if (nums[i] > third&& nums[i] != second&&nums[i]!=first)
			third = nums[i];
	}
	if (third == LONG_MIN)
		return first;
	else 
		return third;
}
int main() {
	int nums[] = { 2 };
	int numsSize = sizeof(nums) / sizeof(int);
	int n = thirdMax(nums, numsSize);
	printf("%d",n);
	return 0;
}