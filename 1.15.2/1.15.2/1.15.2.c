#include<stdlib.h>
#include<Stdio.h>
int isPalindrome(int x) {
	int s = 0;
	int tmp = 0;
	int y = x;
	if (x < 0) {
		return 1;
	}
	while (y!= 0) {
		tmp = y % 10;
		s = s * 10 + tmp;
		y /= 10;
	}
	if (s == x) {
		return 0;
	}
	return 1;
}
int main() {
	int x = 2147483647;
	return isPalindrome(x);
}