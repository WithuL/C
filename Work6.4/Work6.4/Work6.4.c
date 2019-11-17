#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void init(int arr[],int size){
	int i;
	printf("请依次输入十位数字\n");
	for (i=0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	printf("此数组为:\n");
	for (i=0; i < size; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
void empty(int arr[], int size) {
	int i;
	printf("清空数组\n");
	for (i=0; i < size; i++) {
		arr[i] = 0;
	}
	for (i=0; i < size; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
void reverse(int arr[], int size) {
	printf("逆置数组为:\n");
	int i = 0;
	int j = size - 1;
	int tmp = 0;
	for (; i < size; i++) {
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		j--;
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[10];
	int size = 10;
	init(arr, size);
	reverse(arr, size);
	empty(arr, size);
	system("pause");
	return 0;
}
