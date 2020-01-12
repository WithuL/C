#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main() {
	char str[] = "ABCDEFghijk";
	int i = 0;
	int size = strlen(str);
	for (i; i < size; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 'a' + 'A';
		}
	}
	int j = 0;
	for (j; j < size; j++) {
		printf("%c", str[j]);
	}
	system("pause");
	return 0;
}