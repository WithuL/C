#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void max_heapify(int arr[], int start, int end) {
	int dad = start;						//���ڵ�
	int son = dad * 2 + 1;				//���ӽڵ�
	while (son <= end) {
		if (son + 1 <= end && (arr[son + 1] > arr[son])) {
			son++;							//����������ӽڵ㲢�����ӽڵ�����ӽڵ��
											//�Ǿ���sonΪ���ӽڵ�
		}
		if (arr[dad] > arr[son]) {
			return;
		}
		else {
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = 2 * dad + 1;
		}
	}
	return;
}

void heap_sort(int arr[], int len) {
	int i;
	//��ʼ����i�����һ�����ڵ㿪ʼ����
	for (i = len/2-1; i >= 0; i--) {	//��ʱ��i�൱�ڿ�ʼԪ��  len-1�൱�ڽ���Ԫ��
		max_heapify(arr, i, len - 1);
	}
	//�Ƚ���һ��Ԫ�ظ����źõ�ĩβԪ�����������ٽ������ţ�ֱ������
	for (i = len - 1; i > 0; i--) {			
		swap(&arr[0], &arr[i]);				//��ʱ��i-1�൱��ĩβԪ�أ���arr[0]Ϊ��ʼԪ��
		max_heapify(arr, 0, i-1);//��ʱ��֤���Ѿ��滻�����һ��Ԫ�ز����������
	}
}
bool containsDuplicate(int* nums, int numsSize) {
	heap_sort(nums, numsSize);
	int i;
	for (i = 1; i < numsSize; i++) {
		if (nums[i - 1] == nums[i]) {
			return true;
		}
	}
	return false;
}
int main() {
	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	heap_sort(arr, len);
	int i;
	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}