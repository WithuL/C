#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
int fib(int n){
	if (n < 2) {
		return n;
	}
	else {
		int* ret = (int*)malloc(sizeof(int) * n+1);
		ret[0] = 0;
		ret[1] = 1;
		for (int i = 2; i < n + 1; i++) {
			ret[i] = ret[i - 1] + ret[i - 2];
		}
		return ret[n];
	}
}
int main() {
	printf("请输入计算斐波那契数列的第N项:\n");
	int val;
	scanf("%d", &val);
	printf("%d", fib(val));
}