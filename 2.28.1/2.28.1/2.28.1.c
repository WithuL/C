#include<stdio.h>
//返回两个值中最大的那个
int get_max(int num1,int num2){
	if (num1 > num2) return num1;
	else return num2;
}
//
int main1() {
	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0) {
			printf("%d", i);
		}
	}
	return 0;
}
int main() {
	int num1 = 1;
	int num2 = 2;
	int num3 = 3;
	if (num1 < num2) {
		int tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
	if (num1 < num3) {
		int tmp = num1;
		num1 = num3;
		num3 = tmp;
	}
	if (num2 < num3) {
		int tmp = num2;
		num2 = num3;
		num3 = tmp;
	}
	printf("%d%d%d", num1, num2, num3);
	return 0;
}