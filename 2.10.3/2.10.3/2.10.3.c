#include<stdio.h>		
#include<stdlib.h>
// �����Ʒ�
int pivotIndex(int* nums, int numsSize) {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
	}
	for (int i = 0; i < numsSize; i++) {
		if (count * 2 == sum - nums[i]) {
			//�˴������ж�Ϊ:�����������λ������Ԫ�غ����
			//�����Ԫ�صĶ������ڳ�����������Ԫ���������Ԫ�غ�
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