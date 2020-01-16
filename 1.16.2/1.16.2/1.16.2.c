#include<stdio.h>
#include<stdlib.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i, j, tmp;
	for (i = m; i < nums1Size; i++) {
		nums1[i] = nums2[i-m];
	}
	for (i = 0; i < nums1Size; i++) {
		for (j = 1; j < nums1Size; j++) {
			if (nums1[j] < nums1[j - 1]) {
				tmp = nums1[j];
				nums1[j] = nums1[j - 1];
				nums1[j - 1] = tmp;
			}
		}
	}
	i = 0;
	while (i < nums1Size) {
		printf("%d ", nums1[i]);
		i++;
	}
}
int main() {
	int nums1[] = { 1,2,3,0,0,0 };
	int nums2[] = { 2,5,6 };
	int nums1Size = 6;
	int nums2Size = 3;
	int m = 3;
	int n = 3;
	merge(nums1, nums1Size, m, nums2, nums2Size, n);
	system("pause");
	return 0;
}