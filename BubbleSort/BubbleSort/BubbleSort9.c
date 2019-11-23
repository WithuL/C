//从大到小排列
#include<stdio.h>
#include<stdlib.h>
void BubbleSort(int arr[], int size) {
	for (int Bound = 0; Bound < size; Bound++) {
		for (int Cur = size - 1; Cur > Bound; Cur--) {
			if (arr[Cur] < arr[Cur - 1]) {
				int tmp = arr[Cur - 1];
				arr[Cur - 1] = arr[Cur];
				arr[Cur] = tmp;
			}
		}
	}
}
int main() {
	int arr[8] = { 6,3,2,1,6,4,2,7 };
	int size = 8;
	BubbleSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d  ", arr[i]);
	}
	system("pause");
	return 0;
}