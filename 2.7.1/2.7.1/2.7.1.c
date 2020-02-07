#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void max_heapify(int arr[], int start, int end) {
	int dad = start;						//父节点
	int son = dad * 2 + 1;				//左子节点
	while (son <= end) {
		if (son + 1 <= end && (arr[son + 1] > arr[son])) {
			son++;							//如果存在右子节点并且右子节点比左子节点大
											//那就另son为右子节点
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
	//初始化，i从最后一个父节点开始调整
	for (i = len/2-1; i >= 0; i--) {	//此时的i相当于开始元素  len-1相当于结束元素
		max_heapify(arr, i, len - 1);
	}
	//先将第一个元素跟已排好的末尾元素做交换，再进行重排，直到结束
	for (i = len - 1; i > 0; i--) {			
		swap(&arr[0], &arr[i]);				//此时的i-1相当于末尾元素，而arr[0]为开始元素
		max_heapify(arr, 0, i-1);//此时保证了已经替换的最后一个元素不会参与排序
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