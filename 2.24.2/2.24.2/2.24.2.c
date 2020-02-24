#include<stdio.h>
#include<stdlib.h>
int maxSubArray(int* nums, int numsSize) {
	int max = nums[0];
	int sum = 0;
	int	j=INT_MIN; // j��������Ϊ�˷�ֹȫΪ����������  ��j����¼���������ĸ���
	int count = 0; // count�������Ǽ�¼�����ĸ���������������������鳤���򷵻������Ǹ�����
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