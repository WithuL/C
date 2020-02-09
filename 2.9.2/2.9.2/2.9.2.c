#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
int Count_Useful(char* S,int len) {
	int i = 0;
	int count = 0;
	for (i = 0; i < len; i++) {
		if ((S[i] >= 'A' && S[i] <= 'Z') ||
			(S[i] >= 'a' && S[i] <= 'z')) {
			count++;
		}
	}
	return count;
}
void Init(char* P, int uflen,char* S,int len) {
	int i = 0;
	int j = 0;
	for (i = 0; i < len; i++) {
		if ((S[i] >= 'A' && S[i] <= 'Z') ||
			(S[i] >= 'a' && S[i] <= 'z')) {
			P[j] = S[i];
			j++;
		}
	}
}
void Reverse(char* P, int uflen) {
	int left = 0;
	int right = uflen - 1;
	for (; left < right; left++, right--) {
		int tmp = P[left];
		P[left] = P[right];
		P[right] = tmp;
	}
}
char* reverseOnlyLetters(char* S) {
	int len = strlen(S);
	int uflen=Count_Useful(S,len);
	char* P = (char*)malloc(sizeof(char) * uflen+1);
	P[uflen] = '\0';
	Init(P,uflen,S,len);
	Reverse(P, uflen);
	int i = 0;
	int j = 0;
	for (i = 0; i < len; i++) {
		if ((S[i] >= 'A' && S[i] <= 'Z') ||
			(S[i] >= 'a' && S[i] <= 'z')) {
			S[i] = P[j];
			j++;
		}
	}
	return S;
}
int main() {
	char S[] = "Test1ng-Leet=code-Q!";
	puts(S);
	reverseOnlyLetters(S);
	puts(S);
	return 0;
}