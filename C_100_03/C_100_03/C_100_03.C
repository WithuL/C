//一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int i,a,b;
	for (i = 1; i < 9999; i++) {
		a = (int)sqrt(i+100);
		b = (int)sqrt(i + 168);
		if (i+100== a*a) {
			if (i + 168 == b*b) {
				printf("%d\n", i);
			}
		}
	}
	system("pause");
	return 0;
}