#include<stdio.h>
#include<string.h>
#include<malloc.h>
char* replaceSpace(char* s) {
	char* ret = (char*)malloc(sizeof(char) * 10000);
	unsigned i, j;
	for (i = 0,j=0; i<strlen(s); i++) {
		if (s[i] != ' ') {
			ret[j++] = s[i];
		}
		else {
			ret[j++] = '%';
			ret[j++] = '2';
			ret[j++] = '0';
		}
	}
	ret[j] = '\0';
	puts(ret);
	return ret;
}
int main() {
	char s[] = "We Are Happy";
	replaceSpace(s);
	return 0;
}