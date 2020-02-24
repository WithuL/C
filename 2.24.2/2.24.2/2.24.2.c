#include<stdio.h>
#include<stdlib.h>
int maxSubArray(int* nums, int numsSize) {
	int max = nums[0];
	int sum = 0;
	int	j=INT_MIN; // j的设置是为了防止全为负数的数组  用j来记录数组中最大的负数
	int count = 0; // count的作用是记录负数的个数，如果负数个数与数组长度则返回最大的那个负数
	for (int i = 0; i < numsSize; i++) {
		sum = sum + nums[i];
		if (sum < 0) sum = 0;
		if (sum > max) max = sum;
		if (nums[i] > j) j = nums[i];
		if (nums[i] < 0) count++;
	}
	if (count == numsSize) return j; 
	return max;
}
int main() {
	int nums[] = { -2,1,-3,4,-1,2,1,-5,4 };
	int numsSize = sizeof(nums) / sizeof(int);
	return 0;
}