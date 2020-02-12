#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
char* addBinary(char* a, char* b) {
	int alen = strlen(a);
	int blen = strlen(b);
	int anum = 0, bnum = 0, binary = 0, sum = 0;
	int	len = alen > blen ? alen : blen;
	char* c = (char*)malloc(sizeof(char) * (len + 2));
	c[len + 1] = '\0';
	for (--alen, --blen; len >= 0; alen--, --blen, --len) {
		anum = alen > (-1) ? (a[alen] - '0') : 0;
		bnum = blen > (-1) ? (b[blen] - '0') : 0;
		sum = anum + bnum + binary;
		binary = sum / 2;
		c[len] = '0' + sum % 2;
	}
	if (c[0] == '0') {
		return &c[1];
	}
	else {
		return &c[0];
	}
}
int main() {
	char a[] = "11";
	char b[] = "1";
	puts(addBinary(a, b));
	return 0;
}