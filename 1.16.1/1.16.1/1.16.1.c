#include<stdio.h>
#include<Stdlib.h>
int lengthOfLastWord(char* s) {
	int i,j;
	int len = 0;
	while (s[len] != '\0') {
		len++;
	}
	int count = 0;
	for (j = len - 1; j >= 0; j--) {
		if (s[j] != ' ') {
			count++;
			continue;
		}
		else if (s[j] == ' '&&s[j+1]!=' '&&s[j+1]!='\0') {
			return count;
		}
	}
	return count;
}
int main() {
	char s[] = "a       asdfg  ";
	return lengthOfLastWord(s);
}