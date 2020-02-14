#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
bool isPalindrome(char* s) {
	int len = strlen(s);
	char* ret = (char*)malloc(sizeof(char) * (len + 1));
	int i, j;
	for (i = 0, j = 0; i < len + 1; i++) {
		if (isupper(s[i]))
			ret[j++] = tolower(s[i]);
		else if (islower(s[i]) || isdigit(s[i]))
			ret[j++] = s[i];
	}
	ret[j] = '\0';
	for (i = 0, j = j - 1; i < j; i++, j--) {
		if (ret[i] != ret[j])
			return false;
	}
	return true;
}
int main() {
	char s[] = "A man, a plan, a canal: Panama";
	return isPalindrome(s);
}