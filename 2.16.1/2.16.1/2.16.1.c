#include<stdio.h>
#include<string.h>
#include<malloc.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* pair = (int*)malloc(sizeof(int) * 2);
    pair[0] = -1; pair[1] = -1;
    returnSize[0] = 2;
    if (nums == NULL || numsSize == 0)
        return pair;
    int left = 0;
    int right = numsSize;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            right = mid;
        else if (nums[mid] > target)
            right = mid;
        else if (nums[mid] < target)
            left = mid + 1;
    }
    if (right != numsSize && nums[left] == target)
        pair[0] = left;
    left = 0;
    right = numsSize;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid;
        else if (nums[mid] < target)
            left = mid + 1;
    }
    if (left != 0 && nums[left - 1] == target)
        pair[1] = left - 1;
    printf("%d  %d", pair[0], pair[1]);
    return pair;
}
int main() {
	int nums[] = { 5,7,7,8,8,10 };
	int numsSize = sizeof(nums) / sizeof(int);
	int target = 8;
	int returnSize = 0;
	searchRange(nums, numsSize, target, &returnSize);
	return 0;
}