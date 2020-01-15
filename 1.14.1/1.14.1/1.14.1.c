#include<stdio.h>
#include<Stdlib.h>
int main() {
	int nums[5] = { 1,3,5,7};
	int target = 0;
	int numsSize = 2;
	int left = 0;
	int right = numsSize-1;
	int mid = (left+right)/2;
	for (int j = 0; j <numsSize; j++) {
		if (nums[j] == target) {
			while (left < right) {
				mid = (left + right);
				if (target<nums[mid] && target>nums[left]) {
					right = mid;
				}
				if (target == nums[mid]) {
					return mid;
				}
				if (target<nums[right] && target>nums[mid]) {
					left = mid;
				}
			}
			return mid;
		}
		if(j==numsSize-1) {
			for (int i = 0; i < numsSize; i++) {
				if (target < nums[0]) {
					mid = 0;
					return mid;
				}
				else if (target > nums[numsSize - 1]) {
					mid = numsSize;
					return mid;
				}
				else if (target > nums[i] && target < nums[i + 1]) {
					mid = i + 1;
					return mid;
				}
			}
		}
	}
	system("pause");
	return mid;
}