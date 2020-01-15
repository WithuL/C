#include<stdlib.h>
#include<stdio.h>
char canConstruct(char* ransomNote, char* magazine) {
	int sizel = 0;
	int sizer = 0;
	int i, j;
	while (ransomNote[sizel] != '\0') {
		sizel++;
	}
	while (magazine[sizer] != '\0') {
		sizer++;
	}
	int count = 0;
	for (i = 0; i <sizel; i++) {
		for (j = 0; j < sizer; j++) {
			if (ransomNote[i] == magazine[j]) {
				magazine[j] = 'A';
				count += 1;
				break;
			}
		}
	}
	if (count == sizel) {
		return true;
	}
	return false;
}
int main() {
	char ransom[] = "a";
	char magazine[] = "b";
	return canConstruct(ransom, magazine);
}