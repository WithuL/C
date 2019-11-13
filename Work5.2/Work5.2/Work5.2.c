#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
int find(int a[], int size, int tofind) {
	int left = 0;
	int right = size - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid]>tofind) {
			right = mid - 1;
		}
		if (a[mid]<tofind) {
			left = mid + 1;
		}
		if (a[mid]==tofind) {
			printf("找到了，下标为%d\n", mid);
			return mid;
		}
	}
	return -1;
}
int main() {
	int a[] = { 1,3,5,7,9,11,13,15 };
	int size = sizeof(a) / sizeof(a[0]);
	find(a, size, 13);
	system("pause");
	return 0;
}