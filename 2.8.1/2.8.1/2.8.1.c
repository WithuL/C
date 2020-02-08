#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include<string.h>

void freee(int* a, int* b) {
	free(a);
	free(b);
}
int  caculateElement(char* name, int* nameArr) {
	char pre = name[0];
	nameArr[0] = 1;
	int cur = 0;
	int i = 1;
	int len = strlen(name);
	for (i = 1; i < len; i++) {
		if (name[i] == pre) {
			nameArr[cur]++;
		}
		else {
			pre = name[i];
			cur++;
			nameArr[cur] = 1;
		}
	}
	return cur + 1;
}

bool compareNametyped(int* nameArr, int* typedArr, int len) {
	int i = 0;
	for (i = 0; i < len; i++) {
		if (nameArr[i] > typedArr[i]) {
			freee(nameArr, typedArr);
			return false;
		}
	}
	freee(nameArr, typedArr);
	return true;
}

bool isLongPressedName(char* name, char* typed) {
	int* nameArr = (int*)malloc(sizeof(int) * strlen(name));
	int* typedArr = (int*)malloc(sizeof(int) * strlen(typed));
	memset(nameArr, 0, sizeof(int) * strlen(name));
	memset(typedArr, 0, sizeof(int) * strlen(typed));
	int nameLen = caculateElement(name, nameArr);
	int typedLen = caculateElement(typed, typedArr);
	if (nameLen != typedLen) {
		freee(nameArr, typedArr);
		return false;
	}
	else {
		return compareNametyped(nameArr, typedArr, nameLen);
	}
}

int main() {
	char name[] = "alex";
	char typed[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaleex";
	return isLongPressedName(name, typed);
}