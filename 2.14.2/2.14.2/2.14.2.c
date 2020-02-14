#include<stdio.h>
#include<string.h>
int findUnsortedSubarray(int* nums, int numsSize) {
    int posi = 0, posj = numsSize - 1, i, min, max;
    while (posj > posi&& nums[posi] <= nums[posi + 1])posi++;
    while (posj > posi&& nums[posj] >= nums[posj - 1])posj--;
    if (posi == posj)
        return 0;
    min = nums[posi], max = nums[posj];
    for (i = posi; i <= posj; i++)
    {
        if (nums[i] < min)
            min = nums[i];
        if (nums[i] > max)
            max = nums[i];
    }
    posi = 0, posj = numsSize - 1;
    while (nums[posi] <= min)posi++;
    while (nums[posj] >= max)posj--;
    return posj - posi + 1;
}
int main() {
    int nums[] = {2, 6, 4, 8, 10, 9, 15};
	return findUnsortedSubarray(nums,7);
}