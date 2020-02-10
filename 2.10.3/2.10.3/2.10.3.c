#include<stdio.h>		
#include<stdlib.h>
// 逆向推法
int pivotIndex(int* nums, int numsSize) {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
	}
	for (int i = 0; i < numsSize; i++) {
		if (count * 2 == sum - nums[i]) {
			//此处条件判断为:如果中心索引位置左右元素和相等
			//则左边元素的二倍等于除了中心索引元素外的所有元素和
			return i;
		}
		count += nums[i];
	}
	return -1;
}
int main() {
	int nums[] = { 1,7,3,6,5,6 };
	return pivotIndex(nums, 6);
}