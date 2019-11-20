#include<stdio.h>
#include<stdlib.h>
int Multiply(int n, int k) {
	if (k == 1) {
		return n;
	}
	else {
		return n*Multiply(n, k - 1);
	}
}
int main() {
	printf("%d\n",Multiply(2, 8));
	system("pause");
}