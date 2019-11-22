//递归实现strlen
#include<stdlib.h>
#include<stdio.h>
int strlen(char str[]) {
	if (*str != '\0') {
		return 1 + strlen(str + 1);
	}
	return 0;
}
int main() {
	char str[] = "abcde";
	printf("%d\n", strlen(str));
	system("pause");
	return 0;
}

//非递归实现strlen
#include<stdlib.h>
#include<stdio.h>
int main() {
	char str[] = "abcde";
	int i;
	for (i = 0; str[i] != '\0'; i++) {
	}
	printf("%d\n", i);
	system("pause");
	return 0;
}