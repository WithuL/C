//从小到大排列
#include<stdio.h>
#include<stdlib.h>
//此函数为一个冒泡排序函数，分为已排序部分和未排序部分
void BubbleSort(int arr[],int size) {
	//循环已排序和未排序部分的边界，已排序的数组范围为[0,Bound],未排序的数组范围为[Bound,size-1]
	for (int bound = 0; bound < size; bound++) {
		//此时在未排序部分比较大小，从最后一个数组元素开始，与前一个元素相比，把更小的替换为前一位，直到比较到边界
		for (int cur = size-1; cur > bound; cur--) {
			if (arr[cur - 1] > arr[cur]) {
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
	
}
int main() {
	int arr[7] = { 8,4,6,1,3,9,5 };
	int size = 7;
	BubbleSort(arr,size);
	for (int i = 0; i < size; i++) {
		printf("%d  ", arr[i]);
	}
	system("pause");
	return 0;
}