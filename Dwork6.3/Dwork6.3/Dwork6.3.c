#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n) {
	if (n != 0) {
		return n % 10 + DigitSum(n / 10);
	}
	return 0;
}
int main() {
	printf("%d\n", DigitSum(1729));
	system("pause");
}