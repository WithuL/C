#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int myAtoi(char* str) {
	int flag = 1;
	long a = 0;
	for (; *str == 32; str++);
	if (*str == 45) {
		flag = -1;
		str++;
	}
	else if (*str == 43) {
		str++;
	}
	if (*str >='0' && *str <= '9') {
		for (; *str >= '0' && *str <= '9'; str++) {
			a = a * 10 + (*str-'0');
			if (flag==1&&a>INT_MAX) {
				return  INT_MAX;
			}
			if (flag == -1&&flag*a<INT_MIN) {
				return  INT_MIN;
			}
		}
		return flag * (int)a;
	}
	else {
		return 0;
	}
}
int main() {
	char str[] = "-2147483648";
	int a = myAtoi(str);
	printf("%d\n", a);

}